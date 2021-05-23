#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QIcon>

#include "player.h"
#include "playwindow.h"
#include "about.h"

class Game: public QGraphicsView
{
  Q_OBJECT
public:
  Game(QWidget * parent=0);

  QGraphicsScene * scene;
  PlayWindow *playwindow;
  About *sobre;
  QMediaPlayer * music = new QMediaPlayer(this);

  void displayMenu();

public slots:
  void startGame();
  void about();
  void quitGame();
};

#endif // GAME_H
