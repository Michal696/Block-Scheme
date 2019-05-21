// Autori: Vladimír Užík (xuzikv00)
// Derivovaná trieda z Block, spresňuje generický objekt z Block

#include "blockmocnina.h"
#include <cmath>

/**
 * @brief BlockMocnina::BlockMocnina Blok na operáciu mocnina
 * @param parent
 */
BlockMocnina::BlockMocnina(QGraphicsItem *parent) : Block(parent)
{
    blockType = BLOKMOCNINA;
    label = "a ^ b";
    inputPorts = {&a, &b};
    outputPorts = {&out};

}

/**
 * @brief BlockMocnina::doOperation Vykoná operáciu bloku
 */
void BlockMocnina::doOperation() {
    if (a.hasValue && b.hasValue) {
        out.hasValue = true;
        out.value = pow(a.value, b.value);
    }
}
