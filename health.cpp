#include "health.h"
#include "game.h"
#include<QFontDatabase>

extern Game *game;

Health::Health(QGraphicsItem *parent): Score(parent)
{
  health = 5;
  // draw the text
  int id = QFontDatabase::addApplicationFont(":/Fonte/COMICATE.TTF");
  QFontDatabase::applicationFontFamilies(id);
  setPlainText(QString("") + QString::number(health));
  setDefaultTextColor(Qt::black);
  setFont(QFont("COMICATE",40));
}

int Health::decrease()
{
  if(health > 0)
  {
    health--;
     setPlainText(QString("") + QString::number(health));
  }
  else
  {
    game->playwindow->music->stop();
    game->playwindow->music1->setMedia(QUrl("qrc:/Sounds/gameOver_sound.wav"));
    game->playwindow->music1->play();
    game->playwindow->displayGameOverWindow();
  }

  return health;
}

int Health::getHealth()
{
  return health;
}
