#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QPainter>
#include <QWidget>

class Plataforma: public QObject, public QGraphicsItem
{
  Q_OBJECT
public:
  explicit Plataforma(QObject *parent = nullptr);

  QTimer *timer1;
  QPixmap *pixmap;

  int currentframe;

  bool getFalsePlatform(){return isFalse; };

  QRectF boundingRect() const;
  void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
  void move();

private:
  bool isFalse;
};

#endif // PLATAFORMA_H
