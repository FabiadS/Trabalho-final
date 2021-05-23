#include "enemycobra.h"
#include "game.h"

extern Game *game;

EnemyCobra::EnemyCobra(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
  m_spriteCobra();

  QTimer * timer1 = new QTimer();
  connect(timer1, SIGNAL(timeout()), this, SLOT(move()));
  timer1->start(80);

  music = new QMediaPlayer();

  m_walk = 0;
  m_booleana = false;

  QPixmap tam(m_walkDireita.at(0));
  QPixmap aux = tam.scaled(90,80);
  setPixmap(aux);
}

void EnemyCobra::m_spriteCobra()
{
  m_walkDireita.push_back(":/Images/EnemyCobra/walkDireita/walk(1).png");
  m_walkDireita.push_back(":/Images/EnemyCobra/walkDireita/walk(2).png");
  m_walkDireita.push_back(":/Images/EnemyCobra/walkDireita/walk(3).png");
  m_walkDireita.push_back(":/Images/EnemyCobra/walkDireita/walk(4).png");

  m_walkEsquerda.push_back(":/Images/EnemyCobra/walkEsquerda/walk(1).png");
  m_walkEsquerda.push_back(":/Images/EnemyCobra/walkEsquerda/walk(2).png");
  m_walkEsquerda.push_back(":/Images/EnemyCobra/walkEsquerda/walk(3).png");
  m_walkEsquerda.push_back(":/Images/EnemyCobra/walkEsquerda/walk(4).png");

}

void EnemyCobra::m_atualizaCobraEsquerda()
{
  m_walk++;
  if(m_walk == (m_walkEsquerda.size()))
  {
     m_walk = 0;
  }

  QPixmap tam(m_walkEsquerda.at(m_walk));
  QPixmap aux = tam.scaled(90,80);
  setPixmap(aux);
}

void EnemyCobra::m_atualizaCobraDireita()
{
  m_walk++;
  if(m_walk == (m_walkDireita.size()))
  {
     m_walk = 0;
  }

  QPixmap tam(m_walkDireita.at(m_walk));
  QPixmap aux = tam.scaled(90,80);
  setPixmap(aux);
}

void EnemyCobra::m_newCobra()
{
  EnemyCobra *cobra;
  cobra = new EnemyCobra();
  cobra->setPos(100,800);
  game->playwindow->scene->addItem(cobra);
}

void EnemyCobra::move()
{
  if(x()<=100) m_booleana = false;
  else if(x()>=530) m_booleana = true;
  if(m_booleana){
      setPos(x()-5, y());
      m_atualizaCobraEsquerda();
  }
  else{
      setPos(x()+5, y());
      m_atualizaCobraDireita();
  }

  QList<QGraphicsItem *> colliding_item = collidingItems();

  for(int i = 0, n = colliding_item.size(); i < n; i++)
  {
     if(typeid(*(colliding_item[i]))== typeid(Player))
     {
        music->setMedia(QUrl("qrc:/Sounds/sounds_hurt.wav"));
        music->play();
        game->playwindow->health->decrease();
        game->playwindow->player->hurt1->start(50);
        scene()->removeItem(this);
        delete this;

        m_newCobra();
        return;
     }

   }

}
