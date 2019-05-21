// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blockcislo7.h"

/**
 * @brief BlockCislo7::BlockCislo7 Vytvorí datový blok s číslom 7
 * @param parent
 */
BlockCislo7::BlockCislo7(QGraphicsItem *parent) : Block(parent)
{
    blockType = BLOCKCISLO7;
    label = "7";
    outputPorts = {&out};
}

