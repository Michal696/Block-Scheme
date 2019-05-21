#ifndef BLOCKSCENE_H
#define BLOCKSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "blockarrow.h"
#include "block.h"

class BlockScene : public QGraphicsScene
{
    //Q_OBJECT
public:
    enum Mode { InsertLine, MoveItem };
    BlockScene(QObject *parent = 0);
    void setMode(Mode mode);

    QVariantList scene2data();
    void data2scene(QVariantList list);

    void resetAllBlocks();
    bool checkInputPortsBlocks();


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
private:
    QGraphicsLineItem *line;
    Mode myMode;
    Port *inputPort;
    Port *outputPort;
};

#endif // BLOCKSCENE_H
