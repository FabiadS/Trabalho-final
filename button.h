#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QString>

class Button: public QObject, public QGraphicsRectItem
{
  Q_OBJECT
public:
  Button(QString name, QGraphicsItem* parent = nullptr);

  //public methods
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
  void clicked();

private:
  QGraphicsTextItem* text;
};

#endif // BUTTON_H
