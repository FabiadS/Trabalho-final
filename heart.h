#ifndef HEART_H
#define HEART_H

#include <QGraphicsPixmapItem>
#include <QPainter>

class Heart: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Heart(QGraphicsItem *parent=0);
};

#endif // HEART_H
