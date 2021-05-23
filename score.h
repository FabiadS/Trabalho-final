#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>

class Score: public QGraphicsTextItem
{
public:
  Score(QGraphicsItem *parent = 0);
  int increase();
  int getScore();
protected:
  int score, health;
};


#endif // SCORE_H
