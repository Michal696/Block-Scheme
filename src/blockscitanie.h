#ifndef BLOCKSCITANIE_H
#define BLOCKSCITANIE_H

#include "block.h"

class BlockScitanie : public Block
{

public:
    BlockScitanie(QGraphicsItem *parent = 0);
    void doOperation();

    Port a = Port(QRectF(0,10,20,20), false, 0.0);
    Port b = Port(QRectF(0,70,20,20), false, 0.0);
    Port out = Port(QRectF(80, 40, 20, 20), false, 0.0);
};



#endif // BLOCKSCITANIE_H
