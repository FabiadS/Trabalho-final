#include "score.h"
#include "game.h"
#include <QFont>
#include<QFontDatabase>

extern Game *game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
  score = 0;

  // draw the text
  int id = QFontDatabase::addApplicationFont(":/Fonte/COMICATE.TTF");
  QFontDatabase::applicationFontFamilies(id);
  setPlainText(QString("") + QString::number(score));
  setDefaultTextColor(Qt::black);
  setFont(QFont("COMICATE",40));
}

int Score::increase()
{
 score++;
 setPlainText(QString("") + QString::number(score));

 if(score == 10)
 {
     game->playwindow->music->stop();
     game->playwindow->displayWinWindow();
     game->playwindow->music1->setMedia(QUrl("qrc:/Sounds/win_sound.wav"));
     game->playwindow->music1->play();
 }

 return score;

}

int Score::getScore()
{
 return score;
}

