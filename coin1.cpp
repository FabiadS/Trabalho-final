#include "coin1.h"
#include "game.h"

extern Game *game;

Coin1::Coin1(QObject *parent): Coin(parent)
{
  timer = new QTimer();
  timer1 = new QTimer();

  pixmap = new QPixmap(":/Images/Coin/Gold_animation.png");
  currentframe = 0;

  connect(timer, &QTimer::timeout, this, &Coin1::AtualizaCoin);
  timer->start(100);

  connect(timer1, SIGNAL(timeout()), this, SLOT(move()));
  timer1->start(50);

  music = new QMediaPlayer();
}

void Coin1::AtualizaCoin()
{
  currentframe+=68;
  if(currentframe >=680) currentframe=0;

  this->update(-10,-10,68,68);
}

void Coin1::move()
{
  setPos(x(),y()+5);
  if(pos().y() > 800)
  {
    scene()->removeItem(this);
    delete this;
  }

  QList<QGraphicsItem *> colliding_item = collidingItems();
  for(int j = 0, n = colliding_item.size(); j < n; j++)
  {
    if(typeid (*(colliding_item[j]))== typeid (Player))
    {
      music->setMedia(QUrl("qrc:/Sounds/coin_sound.wav"));
      music->play();

      game->playwindow->score->increase();
      scene()->removeItem(this);
      delete this;
      return;
    }

  }
}

QRectF Coin1::boundingRect() const
{
  return QRectF(-10, -10, 68, 68);

}
void Coin1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawPixmap(-10, -10, *pixmap, currentframe, 0, 68, 68);
  Q_UNUSED(option);
  Q_UNUSED(widget);
}


