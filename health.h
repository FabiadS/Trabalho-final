#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QFont>

#include "score.h"


class Health: public Score
{
  Q_OBJECT
public:
 Health(QGraphicsItem *parent = 0);
 int decrease();
 int getHealth();
};

#endif // HEALTH_H
