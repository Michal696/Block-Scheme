// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blocknasobenie.h"

/**
 * @brief BlockNasobenie::BlockNasobenie Blok na operáciu násobenie
 * @param parent
 */
BlockNasobenie::BlockNasobenie(QGraphicsItem *parent) : Block(parent)
{
    blockType = BLOKNASOBENIE;
    label = "a * b";
    inputPorts = {&a, &b};
    outputPorts = {&out};

}

/**
 * @brief BlockNasobenie::doOperation Vykoná operáciu bloku
 */
void BlockNasobenie::doOperation() {
    if (a.hasValue && b.hasValue) {
        out.hasValue = true;
        out.value = a.value * b.value;
    }
}
