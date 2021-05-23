#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>

#include "plataforma.h"
#include "player.h"
#include "score.h"
#include "coin.h"
#include "coin1.h"
#include "health.h"
#include "heart.h"
#include "enemycobra.h"


class PlayWindow: public QGraphicsView
{
  Q_OBJECT
public:
  PlayWindow(QWidget * parent=0);

  QGraphicsScene *scene;
  Player *player;
  Score *score;
  Coin *coin;
  Coin *coin1;
  Health *health;
  Heart *heart;
  EnemyCobra *cobra;
  QMediaPlayer * music = new QMediaPlayer(this);
  QMediaPlayer *music1 = new QMediaPlayer(this);

  QTimer *timer, *timer1, *timer2;

  qreal m_groundlevel;

  void displayGameOverWindow();
  void displayWinWindow();
  void start();
  ~PlayWindow(){ delete player, delete score;};

public slots:
  void restartGame();
  void quitGame();
};


#endif // PLAYWINDOW_H
