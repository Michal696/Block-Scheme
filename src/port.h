#ifndef PORT_H
#define PORT_H

#include <QRectF>

class BlockArrow;

class Port
{
public:
    Port(QRectF rect_, bool hasValue_, double value_);

    QRectF rect;
    BlockArrow *arrow;
    bool hasValue;
    double value;

    void resetPort();

private:
    bool defaultHasValue;
    double defaultValue;
};

#endif // PORT_H
