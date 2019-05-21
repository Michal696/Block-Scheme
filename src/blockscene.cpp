// Autori: Vladimír Užík (xuzikv00)
// Poskytuje platno na ktore sa vykresluju objekty

#include "blockscene.h"
#include "blockcislo5.h"
#include "blockcislo6.h"
#include "blockcislo7.h"
#include "blockscitanie.h"
#include "blockodcitanie.h"
#include "blockscene.h"
#include "blocknasobenie.h"
#include "blockdelenie.h"
#include "blockmocnina.h"

#include <QDebug>

/**
 * @brief BlockScene::BlockScene Inicializuje scénu
 * @param parent
 */
BlockScene::BlockScene(QObject *parent) : QGraphicsScene(parent)
{

    myMode = MoveItem;
    setProperty("mode", myMode);
    line = NULL;
}

/**
 * @brief BlockScene::mousePressEvent Ak je v móde Spojenie vytvorí čiaru ak jej počiatok je vo výstupnom porte bloku, ak je v móde Posun posunie blok
 * @param mouseEvent
 */
void BlockScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (mouseEvent->button() != Qt::LeftButton) {
        return;
    }

    switch (myMode) {
        case InsertLine:
        {
            // pozicia kurzora
            const QPointF point = mouseEvent->scenePos();
            // item kt. sa pod nim nachadza
            QList<QGraphicsItem *>items_at = items(point);
            foreach (QGraphicsItem *item, items_at) {
                 // ak tam niaky je && su to data
                if (item) {
                    // skonevertujem na data typ
                    if (item->type() == Block::Type) {
                        Block *block = qgraphicsitem_cast<Block *>(item);
                        QPointF point_in_rect = block->mapFromScene(point); // namapuje koordinaty kurzoru na BlockItem stvorec
                        // skontrolujem ci sa kurzor nachadza v stvorci urcenom pre spojenie I/O
                        for (int i=0; i < block->outputPorts.size(); i++) {
                            if (block->outputPorts[i]->rect.contains(point_in_rect)) {
                                outputPort = block->outputPorts[i];
                                // pridam ciaru v pripade ze este port ziadnu neobsahuej
                                if (outputPort->arrow == NULL) {
                                    line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),mouseEvent->scenePos()));
                                    addItem(line);
                                }
                                break;
                            }
                        }
                    }

                }
            }
        }
        break;
        case MoveItem: break;
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

/**
 * @brief BlockScene::mouseMoveEvent Presunie druhý koniec čiary pri Spojení, inak presunie Blok na súradnice kurzoru
 * @param mouseEvent
 */
void BlockScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (myMode == InsertLine && line != 0) { // ak je mod Spojenie, potom taham ciaru podla kurzora
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

/**
 * @brief BlockScene::mouseReleaseEvent
 * @param mouseEvent
 */
void BlockScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (line != NULL && myMode == InsertLine) {
        QList<QGraphicsItem *> startItems = items(line->line().p1()); // vybere Itemy na zaciatku ciary, pricom vyhodi samotnu ciaru
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2()); // vybere Itemy na konci ciary, pricom vyhodi samotnu ciaru
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();



        if (startItems.count() > 0 && endItems.count() > 0 && // ak zostali niake Itemy && su to bloky && sa nerovnaju
            startItems.first()->type() == Block::Type &&
            endItems.first()->type() == Block::Type &&
            startItems.first() != endItems.first()) {

            Block *outputBlock = qgraphicsitem_cast<Block *>(startItems.first()); // skonvertujem ich na Bloky
            Block *inputBlock = qgraphicsitem_cast<Block *>(endItems.first());

            bool arrow_input_attached = false;

            QPointF point_in_rect = inputBlock->mapFromScene(line->line().p2()); // podla suradnic konca ciary najdem blok + odpovedajuci port
            for (int i=0; i < inputBlock->inputPorts.size(); i++) {
                if (inputBlock->inputPorts[i]->rect.contains(point_in_rect)) {
                    if (inputBlock->inputPorts[i]->arrow == NULL) { // ak zatial nema ziadnu ciaru, je port validny a poznacim si ho
                         arrow_input_attached = true;
                         inputPort = inputBlock->inputPorts[i];
                    }
                    break;
                }
            }
            removeItem(line); // zmazem ciaru, bude nahradena BlockArrow
            delete line;

            if (arrow_input_attached) { // ak bol port validny nahradim ho BlockArrow
                BlockArrow *arrow = new BlockArrow(outputBlock, inputBlock, outputPort, inputPort);
                outputBlock->setArrow(outputPort, arrow);
                inputBlock->setArrow(inputPort, arrow);
                addItem(arrow);
                arrow->updatePosition();
            }

        } else {
            removeItem(line);
            delete line;
        }

    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

/**
 * @brief BlockScene::setMode Nadstavuje mód medzi spájaním alebo posunom, pri spájaní nechceme aby sa objekty hýbali (šli by so šípkou)
 * @param mode mód ktorý sa nadstavuje
 */
void BlockScene::setMode(Mode mode)
{
    myMode = mode;
    setProperty("mode", myMode); // potrebujem preniest informaciu o mode do bloku, toto je fajn moznost
    QList<QGraphicsItem *>itemList = items(); // ak je mod Spojenie musim znehybnit bloky, inak ich budem tahat spolu s ciarou
    foreach (QGraphicsItem *item, itemList) {
        if (Block *block = qgraphicsitem_cast<Block *>(item)) {
            if (mode == MoveItem) {
                block->setFlag(QGraphicsItem::ItemIsMovable, true);
            } else {
                block->setFlag(QGraphicsItem::ItemIsMovable, false);
            }
        }
    }

}

/**
 * @brief BlockScene::scene2data vytvorí pole z ktorého sa dá rekonštruovať scéna
 * @return
 */
QVariantList BlockScene::scene2data() {

    QList<QGraphicsItem *>itemList = items();
    QVariantList list;
    QVariantList lineList;

    foreach (QGraphicsItem *item, itemList) {
        if (Block *block = qgraphicsitem_cast<Block *>(item)) {
             QVariantHash data;
             data["type"] = block->blockType; // uklada typ a poziciu bloku
             data["pos"] = block->pos();

             foreach (Port *port, block->inputPorts) { // staci ulozit iba pre 1 typ portu
                 if (port->arrow != NULL) {
                     lineList << port->arrow->line(); // ulozi sa pozicia koncov ciary
                 }
             }
             list << data;
        }
    }

    list.push_back(lineList); // nejde list << lineList, mergne namiesto append
    return list;
}

/**
 * @brief BlockScene::data2scene Zrekonštruuje scénu z pola dát
 * @param list pole dát z funckie scene2data
 */
void BlockScene::data2scene(QVariantList list) {

    QList<QVariant> lineList;
    lineList = list.takeLast().toList();

    Block *block;
    foreach (QVariant item, list) {
        QVariantHash data = item.toHash();
        switch (data["type"].toInt()) { // podla ulozeneho typu objektu prida danu triedu do sceny
            case Block::BLOCKCISLO5: block = new BlockCislo5(); break;
            case Block::BLOCKSCITANIE: block = new BlockScitanie(); break;
            case Block::BLOKDELENIE: block = new BlockDelenie(); break;
            case Block::BLOKMOCNINA: block = new BlockMocnina(); break;
            case Block::BLOKNASOBENIE: block = new BlockNasobenie(); break;
            case Block::BLOKODCITANIE: block = new BlockOdcitanie(); break;
            case Block::BLOCKCISLO6: block = new BlockCislo6(); break;
            case Block::BLOCKCISLO7: block = new BlockCislo7(); break;
            default: return;
        }

        block->setPos(data["pos"].toPointF()); // upravi poziciu objektu
        addItem(block);

    }
    foreach (QVariant lineVariant, lineList) { // vytvori prepoje

        QLineF line = lineVariant.toLineF();

        Block *outputBlock = qgraphicsitem_cast<Block *>(itemAt(line.p1(), QTransform())); // blok na zaciatku
        Block *inputBlock = qgraphicsitem_cast<Block *>(itemAt(line.p2(), QTransform())); // blok na konci

        for (int i=0; i < outputBlock->outputPorts.size(); i++) {
            if (outputBlock->outputPorts[i]->rect.contains(outputBlock->mapFromScene(line.p1()))) { // podla suradnic namapuje port
                outputPort = outputBlock->outputPorts[i];
                break;
            }
        }

        for(int i=0; i < inputBlock->inputPorts.size(); i++) {
            if (inputBlock->inputPorts[i]->rect.contains(inputBlock->mapFromScene(line.p2()))) { // podla suradnic namapuje port
                inputPort = inputBlock->inputPorts[i];
                break;
            }
        }

        BlockArrow *arrow = new BlockArrow(outputBlock, inputBlock, outputPort, inputPort); // vytvori prepoj

        outputBlock->setArrow(outputPort, arrow);
        inputBlock->setArrow(inputPort, arrow);

        addItem(arrow);
        arrow->updatePosition();
    }
}

/**
 * @brief BlockScene::resetAllBlocks Resetuje všetky bloky do stavu pri konštrukcii (jedná sa hlavne o porty) + mení notUsed pri šípkach
 *
 */
void BlockScene::resetAllBlocks() {
     QList<QGraphicsItem *>itemList = items(); // zoznam Itemov
     foreach (QGraphicsItem *item, itemList) {
         if (Block *block = qgraphicsitem_cast<Block *>(item)) { // vybere bloky
             block->resetBlock();  // zresetuje blok
         }
     }
     foreach (BlockArrow *arrow, BlockArrow::arrowList) {
         arrow->notUsed = true; // treba pre vypocet
     }
}

/**
 * @brief BlockScene::checkInputPortsBlocks Skontroluje všetky bloky či majú vyplnené porty
 * @return true ak majú, inak false
 */
bool BlockScene::checkInputPortsBlocks() {
     QList<QGraphicsItem *>itemList = items();  // zoznam Itemov
     foreach (QGraphicsItem *item, itemList) {
         if (Block *block = qgraphicsitem_cast<Block *>(item)) { // vybere bloky
             if (!block->checkInputPorts()) { // skontroluje blok
                 return false;
             }
         }
     }
     return true;
}



