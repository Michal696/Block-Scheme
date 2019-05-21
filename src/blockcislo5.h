#ifndef BLOCKCISLO5_H
#define BLOCKCISLO5_H

#include "block.h"

class BlockCislo5 : public Block
{
public:
    Port out = Port(QRectF(80, 40, 20, 20), true, 5);

    BlockCislo5(QGraphicsItem *parent = 0);
};

#endif // BLOCKCISLO5_H
