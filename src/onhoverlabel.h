#ifndef ONHOVERLABEL_H
#define ONHOVERLABEL_H

#include <QGraphicsSimpleTextItem>

class OnHoverLabel : public QGraphicsSimpleTextItem
{
public:
    OnHoverLabel(QGraphicsItem *parent = Q_NULLPTR) : QGraphicsSimpleTextItem(parent) {}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect();
};

#endif // ONHOVERLABEL_H
