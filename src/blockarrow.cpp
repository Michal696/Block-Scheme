// Autori: Vladimír Užík (xuzikv00)
// Vytvára spojenie medzi dvoma blokmi

#include "blockarrow.h"
#include "block.h"

QList<BlockArrow *> BlockArrow::arrowList; // vynulovat pri novej scene


/**
 * @brief BlockArrow::BlockArrow Vytvorí spojenie medzi 2 blokmi
 * @param outputBlock Blok ktorý poskytuje výstup
 * @param inputBlock Blok ktorý poskytuje vstup
 * @param outputPort Port výstupného bloku ktorý figuruje v spojení
 * @param inputPort Port vstupného bloku ktorý figuruje v spojení
 * @param parent
 */
BlockArrow::BlockArrow(Block *outputBlock, Block *inputBlock, Port *outputPort, Port *inputPort, QGraphicsItem *parent) :  QGraphicsLineItem(parent)
{
    myOutputBlock = outputBlock;
    myInputBlock = inputBlock;
    myOutputPort = outputPort;
    myInputPort = inputPort;

    setAcceptHoverEvents(true);
    setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    arrowList.append(this); // pridá šípku do listu -> bude sa používať pre výpočet
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemClipsChildrenToShape, false);
}

QRectF BlockArrow::boundingRect() {
    QRectF rect = QGraphicsLineItem::boundingRect();
    //return rect;
    return rect.marginsAdded(QMarginsF(0,20,0,20)); // kvoli OnHoverLabel
}

/**
 * @brief BlockArrow::updatePosition Obnoví pozíciu šípky (v strede portov na oboch stranách
 */
void BlockArrow::updatePosition()
{
    QLineF line(mapFromItem(myOutputBlock, myOutputPort->rect.center()), mapFromItem(myInputBlock, myInputPort->rect.center()));
    setLine(line);
}

/**
 * @brief BlockArrow::paint Nevykreslí šípku ak sa bloky prekrývajú
 * @param painter
 * @param option
 * @param widget
 */
void BlockArrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (myOutputBlock != NULL && myInputBlock != NULL) {
        if (myOutputBlock->collidesWithItem(myInputBlock)) {
                return;
        }
    }

    QGraphicsLineItem::paint(painter, option, widget);

}
/**
 * @brief BlockArrow::getInputBlock vráti InputBlok spojenia
 * @return
 */
Block *BlockArrow::getInputBlock() {
    return myInputBlock;
}

/**
 * @brief BlockArrow::getOutputBlock vráti OutputBlok spojenia
 * @return
 */
Block *BlockArrow::getOutputBlock() {
    return myOutputBlock;
}

/**
 * @brief BlockArrow::getInputPort vráti InputPort spojenia
 * @return
 */
Port *BlockArrow::getOutputPort() {
    return myOutputPort;
}

/**
 * @brief BlockArrow::getOutputPort vráti OutputPort spojenia
 * @return
 */
Port *BlockArrow::getInputPort() {
    return myInputPort;
}

/**
 * @brief BlockArrow::detachArrow Odpojí šípku z oboch koncov, príprava na zmazanie
 */
void BlockArrow::detachArrow() {
    BlockArrow::arrowList.removeOne(this);
    myInputBlock->setArrow(myInputPort, NULL);
    myOutputBlock->setArrow(myOutputPort, NULL);
}

/**
 * @brief BlockArrow::hoverEnterEvent Zobrazí stav dát na šípke (bolo by fajn keby to bolo ako normala zo stredu)
 * @param event
 */
void BlockArrow::hoverEnterEvent(QGraphicsSceneHoverEvent * event) {
    text = new OnHoverLabel(this);
    QPointF center = (line().p1() + line().p2()) / 2;
    QString text1;
    if (myOutputPort->hasValue) {
        text1 = QString().setNum(myOutputPort->value);
    } else {
        text1 = "N/A";
    }
    text->setPos(center);
    text->setText(text1);
    text->setVisible(true);
    QGraphicsItem::hoverEnterEvent(event);
}

/**
 * @brief BlockArrow::hoverLeaveEvent Skryje stav dát na šípke
 * @param event
 */
void BlockArrow::hoverLeaveEvent(QGraphicsSceneHoverEvent * event) {
    text->setVisible(false);
    QGraphicsItem::hoverLeaveEvent(event);
}
