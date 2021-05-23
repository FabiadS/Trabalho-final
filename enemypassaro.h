#ifndef ENEMYPASSARO_H
#define ENEMYPASSARO_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QVector>
#include <QString>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class EnemyPassaro: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  EnemyPassaro(QGraphicsItem * parent=0);

  QVector <QString> walk;

  QPixmap *pixmap;
  QTimer *timer, *timer1;

  int m_walk;

  QMediaPlayer *music;

  void spritePassaro();
  void atualizaPassaro();

  ~EnemyPassaro(){delete timer, delete timer1;};

public slots:
  void move();

};

#endif // ENEMYPASSARO_H
