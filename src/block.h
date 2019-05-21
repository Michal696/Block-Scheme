#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsColorizeEffect>
#include "port.h"


class BlockArrow;

class Block : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    enum blocks {BLOCKSCITANIE, BLOKODCITANIE, BLOKDELENIE, BLOKNASOBENIE, BLOKMOCNINA, BLOCKCISLO5, BLOCKCISLO6, BLOCKCISLO7};

    blocks blockType;

    QList<Port *> inputPorts;
    QList<Port *> outputPorts;

    enum { Type = UserType + 15 };

    Block(QGraphicsItem *parent = 0);

    void setArrow(Port *port, BlockArrow *arrow);
    void toggleHighlight();
    void resetBlock();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool checkInputPorts();

    virtual void doOperation() {}

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    int type() const override { return Type;}

protected:
    QString label;
    QRectF mainRectangle;
    QGraphicsColorizeEffect *effect;
};

#endif // BLOCK_H
