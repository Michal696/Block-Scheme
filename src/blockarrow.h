#ifndef BLOCKARROW_H
#define BLOCKARROW_H

#include <QLineF>
#include <QGraphicsLineItem>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include "onhoverlabel.h"

class Block;
class Port;

class BlockArrow : public QGraphicsLineItem
{
public:
    BlockArrow(Block *startItem, Block *endItem, Port *startPort, Port *endPort, QGraphicsItem *parent = 0);

    enum { Type = UserType + 16 };

    bool notUsed = true;

    static QList<BlockArrow *> arrowList;
    //QRectF boundingRect() const override;
    void updatePosition();
    Block *getInputBlock();
    Block *getOutputBlock();
    Port *getOutputPort();
    Port *getInputPort();
    void detachArrow();
    QRectF boundingRect();
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    int type() const override { return Type;}

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    OnHoverLabel *text;
    Block *myOutputBlock;
    Block *myInputBlock;
    Port *myOutputPort;
    Port *myInputPort;
};

#endif // BLOCKARROW_H


// QGraphicsTextItem na vstupne bloky
