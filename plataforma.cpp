#include "plataforma.h"
#include <QGraphicsItem>
#include <QDebug>

#include "player.h"
#include "score.h"
#include "game.h"

extern Game *game;

Plataforma::Plataforma(QObject *parent): QObject(parent)
{

  currentframe = 0;

  pixmap = new QPixmap(":/Images/plataforma.png");

  timer1 = new QTimer(this);
  connect(timer1, SIGNAL(timeout()), this, SLOT(move()));
  timer1->start(150);

  int random_number;
  random_number = rand() % 5;
  if(random_number == 0)
  {
      qDebug() << "entrou";
    isFalse = true;
  }
  else{
      isFalse = false;
  }
}

QRectF Plataforma::boundingRect() const
{
  return QRectF(-10, -10, 222,217);
}

void Plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawPixmap(-10, -10, *pixmap, currentframe, 0, 222, 217);

  Q_UNUSED(option);
  Q_UNUSED(widget);
}

void Plataforma::move()
{
  setPos(x(),y()+5);
  setPos(x(),y()+8);
  setPos(x(),y()+6);
  QList<QGraphicsItem *> colliding_item = collidingItems();
  for(int k = 0, n = colliding_item.size(); k < n; k++)
  {

    if(typeid (*(colliding_item[k]))== typeid (Player))
    {
        QPointF aux = pos();
        aux.x();
        aux.y();

        QPointF aux1 = game->playwindow->player->pos();
        aux1.x();
        aux1.y();

        if(getFalsePlatform() == false)
        {
           if((aux.y() > aux1.y())){
              //qDebug() << "player bate em cima";

              game->playwindow->player->setPos(aux1.x(), aux.y()-50);
              game->playwindow->player->isSafe(true); //está na superficie da plataforma (para de cair)

              if(pos().y() > 950)
              {
                game->playwindow->displayGameOverWindow();
                game->playwindow->music->stop();
                game->playwindow->music1->setMedia(QUrl("qrc:/Sounds/gameOver_sound.wav"));
                game->playwindow->music1->play();
              }

           }
           else if(aux.y() <= aux1.y())
           {
              return;
           }
        }
        else{
            scene()->removeItem(this);
            delete this;
        }
     }
 }

  if(pos().y() >950)
  {
    scene()->removeItem(this);
    delete this;
  }
}
