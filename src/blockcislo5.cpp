// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blockcislo5.h"

/**
 * @brief BlockData::BlockData Vytvorí datový blok s číslom 5
 * @param parent
 */
BlockCislo5::BlockCislo5(QGraphicsItem *parent) : Block(parent)
{
    blockType = BLOCKCISLO5;
    label = "5";
    outputPorts = {&out};
}
