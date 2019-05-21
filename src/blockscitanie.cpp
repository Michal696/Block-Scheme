// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blockscitanie.h"

/**
 * @brief BlockScitanie::BlockScitanie Blok na operáciu odčítanie
 * @param parent
 */
BlockScitanie::BlockScitanie(QGraphicsItem *parent) : Block(parent)
{
    blockType = BLOCKSCITANIE;
    label = "a + b";
    inputPorts = {&a, &b};
    outputPorts = {&out};

}

/**
 * @brief BlockScitanie::doOperation Vykoná operáciu bloku
 */
void BlockScitanie::doOperation() {
    if (a.hasValue && b.hasValue) {
        out.hasValue = true;
        out.value = a.value + b.value;
    }
}

