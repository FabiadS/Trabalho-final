#include "enemypassaro.h"
#include "game.h"

Game *game;

EnemyPassaro::EnemyPassaro(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
  spritePassaro();

  QPixmap tam(walk.at(0));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

  m_walk = 0;

  timer1 = new QTimer();
  connect(timer1, SIGNAL(timeout()), this, SLOT(move()));
  timer1->start(30);

  timer = new QTimer();
  connect(timer, &QTimer::timeout, this, &EnemyPassaro::atualizaPassaro);
  timer->start(100);

  music = new QMediaPlayer();
}

void EnemyPassaro::spritePassaro()
{
  walk.push_back(":/Images/EnemyPassaro/walk/walk(1).png");
  walk.push_back(":/Images/EnemyPassaro/walk/walk(2).png");
  walk.push_back(":/Images/EnemyPassaro/walk/walk(3).png");
  walk.push_back(":/Images/EnemyPassaro/walk/walk(4).png");

}

void EnemyPassaro::atualizaPassaro()
{
  m_walk++;
  if(m_walk == (walk.size()))
  {
     m_walk = 0;
  }

  QPixmap tam(walk.at(m_walk));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

}

void EnemyPassaro::move()
{
  setPos(x()+5,y());

  // verificação de colisão:
  QList<QGraphicsItem *> colliding_item = collidingItems();

  for(int i = 0, n = colliding_item.size(); i < n; i++)
  {
     if(typeid(*(colliding_item[i]))== typeid(Player))
     {
        music->setMedia(QUrl("qrc:/Sounds/sounds_hurt.wav"));
        music->play();
        game->playwindow->health->decrease();
        game->playwindow->player->hurt1->start(100);
        scene()->removeItem(this);
        delete this;

        return;
     }

   }
  if(pos().x() > 800)
  {
    scene()->removeItem(this);
    delete this;
  }


}
