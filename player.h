#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QRectF>
#include <QVector>
#include <QImage>
#include <QPixmap>

class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);

    QTimer* Jump, *Right, *Left, *timer, *timer2, *idle1, *idle2, *hurt1, *timerJ, *jump1, *jump2;
    QPixmap *pixmap;

    qreal groundY;

    QVector <QString> spriteDead;
    QVector <QString> spriteIdleEsquerda;
    QVector <QString> spriteIdleDireita;
    QVector <QString> spriteJumpDireita;
    QVector <QString> spriteJumpEsquerda;
    QVector <QString> spriteRunDireita;
    QVector <QString> spriteRunEsquerda;
    QVector <QString> spriteHurtEsquerda;
    QVector <QString> spriteHurtDireita;

    void isSafe(bool status);  //modificar o status do boneco
    void sprite();

    QMediaPlayer *music;

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);

private:

    int contador;   //conta o tempo
    bool pula, parado;  //verifica o estado do boneco
    int run, stop, hurt, m_jump;

    int mode;

signals:


public slots:
    void spawn();
    void spawnPassaro();
    void coins();
    void jump(int changeMode);
    void newJump(); //pula e cai
    void AtualizaRunDireita();
    void AtualizaRunEsquerda();
    void AtualizaIdleDireita();
    void AtualizaIdleEsquerda();
    void AtualizaMachucadoEsquerda();
    void AtualizaJumpEsquerda();
    void AtualizaJumpDireita();

};

#endif // PLAYER_H
