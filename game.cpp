#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QTimer>
#include <QObject>
#include "button.h"
#include "game.h"
#include "about.h"
#include "player.h"
#include "playwindow.h"

PlayWindow *playwindow;

Game::Game(QWidget *parent): QGraphicsView(parent)
{
  scene = new QGraphicsScene();

  setWindowTitle("Fabi's Jumps");

  scene->setSceneRect(0, 0, 800, 950);
  scene->setBackgroundBrush(QBrush(QImage(":/Images/background.png")));

  setScene(scene);

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setFixedSize(800, 950);

  // adicionar game music
  music->setMedia(QUrl("qrc:/Sounds/game_sound.wav"));
  music->play();

}

void Game::startGame()
{
  this->close();
  playwindow = new PlayWindow();
}

void Game::about()
{
 sobre = new About();
 sobre->information();

}

void Game::quitGame()
{
  this->close();

}

void Game::displayMenu()
{
  //clean the scene
  scene->clear();

  //create the title text
  QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("FABI'S JUMPS"));
  QFont textFont("karantina", 30);
  titleText->setFont(textFont);

  int textX = this->width()/2 - titleText->boundingRect().width()/2;
  int textY = 250;

  titleText->setPos(textX, textY);
  scene->addItem(titleText);

  //create the play button
  Button *playbutton = new Button(QString("START"));
  int btX = this->width()/2 - playbutton->boundingRect().width()/2;
  int btY = 350;

  playbutton->setPos(btX, btY);
  connect(playbutton, SIGNAL(clicked()), this, SLOT(startGame()));
  scene->addItem(playbutton);

  //create the quit button
  Button *quitbutton = new Button(QString("QUIT"));
  int qtX = this->width()/2 - quitbutton->boundingRect().width()/2;
  int qtY = 550;

  quitbutton->setPos(qtX, qtY);
  connect(quitbutton, SIGNAL(clicked()), this, SLOT(quitGame()));
  scene->addItem(quitbutton);

  //create the information button
  Button *informationbutton = new Button(QString("ABOUT"));
  int inX = this->width()/2 - informationbutton->boundingRect().width()/2;
  int inY = 450;

  informationbutton->setPos(inX, inY);
  connect(informationbutton, SIGNAL(clicked()), this, SLOT(about()));
  scene->addItem(informationbutton);

}
