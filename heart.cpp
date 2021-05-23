#include "heart.h"

Heart::Heart(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
  QPixmap tam(":/Images/Health/heart1.png");
  QPixmap aux = tam.scaled(80,70);
  setPixmap(aux);
}

