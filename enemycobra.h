#ifndef ENEMYCOBRA_H
#define ENEMYCOBRA_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QObject>
#include <QVector>
#include <QTimer>

class EnemyCobra:  public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  EnemyCobra(QGraphicsItem * parent=0);

  QVector <QString> m_walkDireita;
  QVector <QString> m_walkEsquerda;

  QPixmap *m_pixmap;
  QTimer *m_timer;
  QMediaPlayer *music;

  void m_spriteCobra();
  void m_atualizaCobraEsquerda();
  void m_atualizaCobraDireita();
  void m_newCobra();

  int m_walk;
  bool m_booleana;

public slots:
  void move();
};

#endif // ENEMYCOBRA_H
