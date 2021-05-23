#include "playwindow.h"
#include "game.h"
#include "button.h"
#include <QProcess>
#include <QGraphicsPixmapItem>
#include <QPixmap>

extern Game *game;

PlayWindow::PlayWindow(QWidget *parent): QGraphicsView(parent)
{
  timer = new QTimer();
  timer1 = new QTimer();
  timer2 = new QTimer();

  scene = new QGraphicsScene();

  scene->setSceneRect(0, 0, 800, 950);
  scene->setBackgroundBrush(QBrush(QImage(":/Images/background.png")));

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setFixedSize(800, 950);
  setScene(scene);

  game->music->stop();
  // adicionar som de click
  music->setMedia(QUrl("qrc:/Sounds/start_music.mp3"));
  music->play();

  score = new Score();
  scene->addItem(score);

  coin = new Coin();
  coin->setPos(60, 20);
  scene->addItem(coin);

  coin1 = new Coin1();
  coin1->setPos(1300, m_groundlevel - coin1->boundingRect().height()-200);
  scene->addItem(coin1);

  health = new Health();
  health->setPos(health->x(), health->y()+65);
  scene->addItem(health);

  heart = new Heart();
  heart->setPos(40,65);
  scene->addItem(heart);

  cobra = new EnemyCobra();
  cobra->setPos(100,800);
  scene->addItem(cobra);


  // criar o jogador
   player = new Player();
   // definir a posição padrão do jogador para ser em baixo da tela
   // por definição a visualização é centralizada para pegar todos os objetos
   player->setPos(400,770);
   // colocar o foco no jogador
   player->setFlag(QGraphicsItem::ItemIsFocusable);
   player->setFocus();
   // adicionar o jogador no cenario
   scene->addItem(player);

  // criar inimigos e coins

  QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
  timer->start(2000);
  QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawnPassaro()));
  timer1->start(3000);
  QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(coins()));
  timer2->start(4000);

  show();
}


void PlayWindow::displayGameOverWindow()
{
  for(size_t i = 0, n = scene->items().size(); i < n; i++)
  {
      scene->items().at(i)->hide();
  }
  timer->stop();
  timer1->stop();
  timer2->stop();

  QGraphicsRectItem *foto = new QGraphicsRectItem(0,0,500,700);
  scene->addItem(foto);
  foto->setPos(130,70);
  foto->setBrush(QBrush(QImage(":/Images/game_over (1).png")));

  //play again Button
  Button *playagain = new Button(QString("PLAY AGAIN"));
  int btX = 170;
  int btY = 510;

  playagain->setPos(btX, btY);
  connect(playagain, SIGNAL(clicked()), this, SLOT(restartGame()));
  scene->addItem(playagain);

  //quit game button
  Button *quit = new Button(QString("QUIT"));
  int qtX = 380;
  int qtY = 510;

  quit->setPos(qtX, qtY);
  connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
  scene->addItem(quit);
}

void PlayWindow::displayWinWindow()
{
  for(size_t i = 0, n = scene->items().size(); i < n; i++)
  {
      scene->items().at(i)->hide();
  }
  timer->stop();
  timer1->stop();
  timer2->stop();

  QGraphicsRectItem *foto = new QGraphicsRectItem(0,0,500,700);
  scene->addItem(foto);
  foto->setPos(130,70);
  foto->setBrush(QBrush(QImage(":/Images/win(1).png")));

  //play again Button
  Button *playagain = new Button(QString("PLAY AGAIN"));
  int btX = 170;
  int btY = 510;

  playagain->setPos(btX, btY);
  connect(playagain, SIGNAL(clicked()), this, SLOT(restartGame()));
  scene->addItem(playagain);

  //quit game button
  Button *quit = new Button(QString("QUIT"));
  int qtX = 380;
  int qtY = 510;

  quit->setPos(qtX, qtY);
  connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
  scene->addItem(quit);
}

void PlayWindow::start()
{
  game->playwindow = new PlayWindow();
}

void PlayWindow::restartGame()
{
  game->playwindow->timer->stop();
  game->playwindow->timer1->stop();
  game->playwindow->timer2->stop();
  game->playwindow->close();
  start();

}

void PlayWindow::quitGame()
{
  this->close();
}

