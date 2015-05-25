#ifndef DEBUG_H
#define DEBUG_H

#include <QGraphicsTextItem>

class Debug: public QGraphicsTextItem
{
public:
    Debug(QGraphicsItem *parent=0);
    void updatePlayerCoordinates(int x, int y);
};

#endif // DEBUG_H
