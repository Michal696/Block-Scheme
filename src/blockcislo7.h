#ifndef BLOCKCISLO7_H
#define BLOCKCISLO7_H


#include "block.h"

class BlockCislo7 :  public Block
{
public:
    Port out = Port(QRectF(80, 40, 20, 20), true, 7);

    BlockCislo7(QGraphicsItem *parent = 0);
};

#endif // BLOCKCISLO7_H
