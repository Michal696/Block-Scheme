// Autori: Vladimír Užík (xuzikv00)
// Generický model bloku, bázova trieda pre všetky bloky

#include "block.h"
#include "blockarrow.h"
#include "blockscene.h"

/**
 * @brief Block::Block inicializuje zvýraznenie a štvorec bloku, nadstaví flagy
 * @param parent
 */
Block::Block(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    mainRectangle = QRectF(0, 0, 100, 100);
    setRect(mainRectangle);

    effect = new QGraphicsColorizeEffect(this);
    effect->setEnabled(false);

    setGraphicsEffect(effect);

    setAcceptHoverEvents(true);
    setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

/**
 * @brief Block::paint Dokreslí porty (malé štvorce na boku bloku)
 * @param painter
 * @param option
 * @param widget
 */
void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    foreach (Port* input, inputPorts) {
        painter->drawRect(input->rect);
    }

    foreach (Port* output, outputPorts) {
        painter->drawRect(output->rect);
    }

    painter->drawText(mainRectangle, Qt::AlignCenter | Qt::AlignVCenter, label);
    QGraphicsRectItem::paint(painter, option, widget);
}
/**
 * @brief Block::itemChange Obnoví súradnice šípky keď sa zmení poloha bloku
 * @param change
 * @param value
 * @return
 */
QVariant Block::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange) {
            foreach (Port *port, inputPorts) {
                if (port->arrow != NULL) {
                     port->arrow->updatePosition();
                }

            }
            foreach (Port *port, outputPorts) {
                if (port->arrow != NULL) {
                     port->arrow->updatePosition();
                }

            }
        }
    if (change == QGraphicsItem::ItemSceneHasChanged) {
        if (scene()->property("mode") == BlockScene::MoveItem) {
            setFlag(QGraphicsItem::ItemIsMovable, true);
        } else {
            setFlag(QGraphicsItem::ItemIsMovable, false);
        }
    }

        //return value;
    return QGraphicsItem::itemChange(change, value);


}

/**
 * @brief Block::toggleHighlight Prepína zvýraznenie bloku
 */
void Block::toggleHighlight() {
    if (effect->isEnabled()) {
        effect->setEnabled(false);
    } else {
        effect->setEnabled(true);
    }
}

/**
 * @brief Block::setArrow Nadstaví port aby používal danú šípku
 * @param port Pointer na port
 * @param arrow Pointer na šípku
 */
void Block::setArrow(Port *port, BlockArrow *arrow)
{
    port->arrow = arrow;
}


/**
 * @brief Block::resetBlock zresetuje všetky bloky do pôvodného stavu
 */
void Block::resetBlock() {
    effect->setEnabled(false);
    foreach (Port *port, inputPorts) {
        port->resetPort();

    }
    foreach (Port *port, outputPorts) {
        port->resetPort();

    }
}

/**
 * @brief Block::checkInputPorts kontroluje či sú všetky vstupné porty spojené
 * @return true ak hej, inak false
 */
bool Block::checkInputPorts() {
    effect->setColor(Qt::blue);
    effect->setEnabled(false);
    foreach (Port *port, inputPorts) {
        if(port->arrow == NULL) {
            effect->setColor(Qt::red);
            effect->setEnabled(true);
            return false;
        }
    }
    return true;
}



