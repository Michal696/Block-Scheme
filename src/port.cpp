// Autori: Vladimír Užík (xuzikv00)
// Popisuje port bloku (vstupný aj výstupný)`

#include "port.h"

/**
 * @brief Port::Port Trieda ktorá rieši porty blokov
 * @param rect_ umiestnenie portu
 * @param hasValue_ true ak port má implicitnú hodnotu, inak false
 * @param value_ implicitná hodnota portu
 */
Port::Port(QRectF rect_, bool hasValue_, double value_)
{
    rect = rect_;
    arrow = NULL;
    hasValue = hasValue_;
    value = value_;
    defaultHasValue = hasValue_;
    defaultValue = value_;
}

/**
 * @brief Port::resetPort Nadstaví port do stavu pri konštrukcii
 */
void Port::resetPort() {
    hasValue = defaultHasValue;
    value = defaultValue;
}
