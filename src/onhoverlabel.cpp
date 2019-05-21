// Autori: Vladimír Užík (xuzikv00)
// Zobrazí informáciu na spoji ak je kurzor nad spojom
#include <QDebug>

#include "onhoverlabel.h"
#include <QPainter>

/**
 * @brief OnHoverLabel::boundingRect Zvacsi velkost Itemu
 * @return
 */
QRectF OnHoverLabel::boundingRect() {
    QRectF rect = QGraphicsSimpleTextItem::boundingRect();
    return rect.marginsAdded(QMarginsF(20,20,20,20)); // prida ku stvorcu +20 z kazdej strany
}

/**
 * @brief OnHoverLabel::paint Vyplni pozadie Itemu zltou farbou
 * @param painter
 * @param option
 * @param widget
 */
void OnHoverLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::yellow); // zlte pozadie
    painter->drawRect(boundingRect());
    QGraphicsSimpleTextItem::paint(painter, option, widget);
}
