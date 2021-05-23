#ifndef COIN1_H
#define COIN1_H

#include "coin.h"
#include <QMediaPlayer>
#include <QTimer>

class Coin1: public Coin
{
  Q_OBJECT
public:
  explicit Coin1(QObject *parent = nullptr);

  QTimer *timer, *timer1;

  QRectF boundingRect() const;
  void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

  QMediaPlayer *music;

public slots:
  void AtualizaCoin();
  void move();

};

#endif // COIN1_H
