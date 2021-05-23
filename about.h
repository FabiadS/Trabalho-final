#ifndef ABOUT_H
#define ABOUT_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QIcon>

class About: public QGraphicsView
{
public:
  About(QWidget * parent=0);
  void information();

private:

 QGraphicsScene *scene;


};

#endif // ABOUT_H
