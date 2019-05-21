#ifndef BLOCKCISLO6_H
#define BLOCKCISLO6_H

#include "block.h"

class BlockCislo6 :  public Block
{
public:
    Port out = Port(QRectF(80, 40, 20, 20), true, 6);

    BlockCislo6(QGraphicsItem *parent = 0);
};

#endif // BLOCKCISLO6_H
