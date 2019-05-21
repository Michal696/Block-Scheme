#ifndef BLOKNASOBENIE_H
#define BLOKNASOBENIE_H

#include "block.h"

class BlockNasobenie : public Block
{
public:
    BlockNasobenie(QGraphicsItem *parent = 0);

    void doOperation();

    Port a = Port(QRectF(0,10,20,20), false, 0.0);
    Port b = Port(QRectF(0,70,20,20), false, 0.0);
    Port out = Port(QRectF(80, 40, 20, 20), false, 0.0);
};


#endif // BLOKNASOBENIE_H
