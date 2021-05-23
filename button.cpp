#include "button.h"
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QEvent>


Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
  setRect(0, 0, 200, 50);
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::green);
  setBrush(brush);

  //draw the text
  text = new QGraphicsTextItem(name, this);
  int xPos = rect().width()/2 - text->boundingRect().width()/2;
  int yPos = rect().height()/2 - text->boundingRect().height()/2;
  text->setPos(xPos, yPos);

  //allow responding to hover events
  setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  emit clicked();
  QMediaPlayer * music = new QMediaPlayer(this);
  // adicionar som de click
  music->setMedia(QUrl("qrc:/Sounds/button_click.wav"));
  music->play();

  Q_UNUSED(event);

}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
  //change color to darkGreen
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt:: darkGreen);
  setBrush(brush);

  Q_UNUSED(event);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent*event)
{
  //change the color to green
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::green);
  setBrush(brush);

  Q_UNUSED(event);
}

