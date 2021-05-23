#include "coin.h"

Coin::Coin(QObject *parent): QObject(parent)
{
  pixmap = new QPixmap(":/Images/Coin/coin_image.png");
  currentframe = 0;
}

QRectF Coin::boundingRect() const
{
  return QRectF(-10, -10, 60, 60);
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawPixmap(-10, -10, *pixmap, currentframe, 0, 60, 60);

  Q_UNUSED(option);
  Q_UNUSED(widget);
}


