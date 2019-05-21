// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blockdelenie.h"

/**
 * @brief BlockDelenie::BlockDelenie Blok na operáciu delenie
 * @param parent
 */
BlockDelenie::BlockDelenie(QGraphicsItem *parent) : Block(parent)
{
    blockType = BLOKDELENIE;
    label = "a / b";
    inputPorts = {&a, &b};
    outputPorts = {&out};

}

/**
 * @brief BlockDelenie::doOperation Blok vykoná operáciu delenie
 */
void BlockDelenie::doOperation() {
    if (a.hasValue && b.hasValue) {
        out.hasValue = true;
        out.value = a.value / b.value;
    }
}
