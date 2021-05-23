#ifndef COIN_H
#define COIN_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPainter>
#include <QWidget>

class Coin: public QObject, public QGraphicsItem
{
  Q_OBJECT
public:
  explicit Coin(QObject *parent = nullptr);  

  QRectF boundingRect() const;
  void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

  int currentframe;
  QPixmap *pixmap;

};

#endif // COIN_H
