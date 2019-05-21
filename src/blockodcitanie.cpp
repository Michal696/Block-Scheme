// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blockodcitanie.h"

/**
 * @brief BlockOdcitanie::BlockOdcitanie Blok na operáciu odčítanie
 * @param parent
 */
BlockOdcitanie::BlockOdcitanie(QGraphicsItem *parent) : Block(parent) // spravit koncovy blok a zvyraznit ho
{
    blockType = BLOKODCITANIE;
    label = "a - b";
    inputPorts = {&a, &b};
    outputPorts = {&out};

}

/**
 * @brief BlockOdcitanie::doOperation Vykoná operáciu bloku
 */
void BlockOdcitanie::doOperation() {
    if (a.hasValue && b.hasValue) {
        out.hasValue = true;
        out.value = a.value - b.value;
    }
}
