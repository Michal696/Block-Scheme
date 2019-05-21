// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blockcislo6.h"

/**
 * @brief BlockCislo6::BlockCislo6 Vytvorí datový blok s číslom 6
 * @param parent
 */
BlockCislo6::BlockCislo6(QGraphicsItem *parent) : Block(parent)
{
    blockType = BLOCKCISLO6;
    label = "6";
    outputPorts = {&out};
}

