#include "player.h"
#include "plataforma.h"
#include "enemypassaro.h"
#include "enemycobra.h"
#include "playwindow.h"
#include "plataforma.h"
#include "coin1.h"
#include "game.h"
#include <QPointF>

#include <iostream>

extern Game *game;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
  sprite();

  run = 0;
  stop = 0;
  hurt = 0;
  m_jump = 0;

  Right = new QTimer(this);
  Left = new QTimer(this);

  connect(Left, SIGNAL(timeout()), this, SLOT(AtualizaRunEsquerda()));
  connect(Right, SIGNAL(timeout()), this, SLOT(AtualizaRunDireita()));

  idle1 = new QTimer(this);
  idle2 = new QTimer(this);

  connect(idle2, SIGNAL(timeout()), this, SLOT(AtualizaIdleEsquerda()));
  connect(idle1, SIGNAL(timeout()), this, SLOT(AtualizaIdleDireita()));

  hurt1 = new QTimer(this);
  connect(hurt1, SIGNAL(timeout()), this, SLOT(AtualizaMachucadoEsquerda()));

  contador = 0;
  pula = false;
  parado = true;

  timerJ = new QTimer(this);
  connect(timerJ, SIGNAL(timeout()), this, SLOT(newJump()));
  timerJ->start(15);

  jump1 = new QTimer(this);
  jump2 = new QTimer(this);

  connect(jump1, SIGNAL(timeout()), this, SLOT(AtualizaJumpEsquerda()));
  connect(jump2, SIGNAL(timeout()), this, SLOT(AtualizaJumpDireita()));

  QPixmap tam(spriteRunDireita.at(0));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

}

void Player::sprite()
{
  spriteIdleDireita.push_back(":/Images/Player/IdleDireita/Idle (1).png");
  spriteIdleDireita.push_back(":/Images/Player/IdleDireita/Idle (2).png");
  spriteIdleDireita.push_back(":/Images/Player/IdleDireita/Idle (3).png");
  spriteIdleDireita.push_back(":/Images/Player/IdleDireita/Idle (4).png");

  spriteIdleEsquerda.push_back(":/Images/Player/IdleEsquerda/Idle (1).png");
  spriteIdleEsquerda.push_back(":/Images/Player/IdleEsquerda/Idle (2).png");
  spriteIdleEsquerda.push_back(":/Images/Player/IdleEsquerda/Idle (3).png");
  spriteIdleEsquerda.push_back(":/Images/Player/IdleEsquerda/Idle (4).png");

  spriteHurtEsquerda.push_back(":/Images/Player/HurtEsquerda/Hurt (1).png");
  spriteHurtEsquerda.push_back(":/Images/Player/HurtEsquerda/Hurt (2).png");
  spriteHurtEsquerda.push_back(":/Images/Player/HurtEsquerda/Hurt (3).png");
  spriteHurtEsquerda.push_back(":/Images/Player/HurtEsquerda/Hurt (4).png");

  spriteHurtDireita.push_back(":/Images/Player/HurtDireita/Hurt (1).png");
  spriteHurtDireita.push_back(":/Images/Player/HurtDireita/Hurt (2).png");
  spriteHurtDireita.push_back(":/Images/Player/HurtDireita/Hurt (3).png");
  spriteHurtDireita.push_back(":/Images/Player/HurtDireita/Hurt (4).png");

  spriteJumpEsquerda.push_back(":/Images/Player/JumpEsquerda1/Jump (1).png");
  spriteJumpEsquerda.push_back(":/Images/Player/JumpEsquerda1/Jump (2).png");
  spriteJumpEsquerda.push_back(":/Images/Player/JumpEsquerda1/Jump (3).png");
  spriteJumpEsquerda.push_back(":/Images/Player/JumpEsquerda1/Jump (4).png");
  spriteJumpEsquerda.push_back(":/Images/Player/JumpEsquerda1/Jump (5).png");
  spriteJumpEsquerda.push_back(":/Images/Player/JumpEsquerda1/Jump (6).png");
  spriteJumpEsquerda.push_back(":/Images/Player/JumpEsquerda1/Jump (7).png");

  spriteJumpDireita.push_back(":/Images/Player/JumpDireita1/Jump (1).png");
  spriteJumpDireita.push_back(":/Images/Player/JumpDireita1/Jump (2).png");
  spriteJumpDireita.push_back(":/Images/Player/JumpDireita1/Jump (3).png");
  spriteJumpDireita.push_back(":/Images/Player/JumpDireita1/Jump (4).png");
  spriteJumpDireita.push_back(":/Images/Player/JumpDireita1/Jump (5).png");
  spriteJumpDireita.push_back(":/Images/Player/JumpDireita1/Jump (6).png");
  spriteJumpDireita.push_back(":/Images/Player/JumpDireita1/Jump (7).png");


  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (1).png"));
  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (2).png"));
  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (3).png"));
  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (4).png"));
  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (5).png"));
  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (6).png"));
  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (7).png"));
  spriteRunDireita.push_back((":/Images/Player/RunDireita/Run (8).png"));

  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (1).png"));
  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (2).png"));
  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (3).png"));
  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (4).png"));
  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (5).png"));
  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (6).png"));
  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (7).png"));
  spriteRunEsquerda.push_back((":/Images/Player/RunEsquerda/Run (8).png"));

}

void Player::keyPressEvent(QKeyEvent *event)
{

  if(event->key() == Qt::Key_Left)
  {
     if(Left->remainingTime() > 0)
     {
        //qDebug() << "remaining time" << Left->remainingTime();
     }

     setPos(x()-10, y());
     Left->start(100);

  }
  else if(event->key() == Qt::Key_Right)
  {
      if(Right->remainingTime() > 0)
      {
         //qDebug() << "remaining time" << Right->remainingTime();
      }

      setPos(x()+10, y());
      Right->start(100);
  }
  else if(event->key() == Qt::Key_Down)
  {
     setPos(x(),y()+10);
  }
  else if(event->key() == Qt::Key_A)
  {
     jump(3);
     jump2->start(50);
  }

  else if(event->key() == Qt::Key_D)
  {
     jump(2);
     jump1->start(50);
  }
  else if(event->key() == Qt::Key_W)
  {
      jump(1);

  }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
  if(event->key() == Qt::Key_Left)
  {
      idle2->start(200);
  }
  else if(event->key() == Qt::Key_Right)
  {
      idle1->start(200);
  }
  if(event->key() == Qt::Key_A)
  {
      idle2->start(200);
  }
  else if(event->key() == Qt::Key_D)
  {
      idle1->start(200);
  }

}

void Player::AtualizaRunEsquerda()
{
  run++;
  if(run == spriteRunEsquerda.size())
  {
     run = 0;
  }

  QPixmap tam(spriteRunEsquerda.at(run));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

  Left->stop();
}

void Player::AtualizaIdleDireita()
{

  stop++;
  if(stop == spriteIdleDireita.size())
  {
     stop = 0;
  }

  QPixmap tam(spriteIdleDireita.at(stop));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

  idle1->stop();

}

void Player::AtualizaIdleEsquerda()
{

  stop++;
  if(stop == spriteIdleEsquerda.size())
  {
     stop = 0;
  }

  QPixmap tam(spriteIdleEsquerda.at(stop));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

  idle2->stop();

}

void Player::AtualizaMachucadoEsquerda()
{
  hurt++;
  if(hurt == spriteHurtEsquerda.size())
  {
     hurt = 0;
  }

  QPixmap tam(spriteHurtEsquerda.at(hurt));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

  hurt1->stop();
}

void Player::AtualizaJumpEsquerda()
{
  m_jump++;
  if(m_jump == spriteJumpDireita.size())
  {
     m_jump = 0;
  }

  QPixmap tam(spriteJumpDireita.at(m_jump));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

  jump1->stop();
}

void Player::AtualizaJumpDireita()
{
  m_jump++;
  if(m_jump == spriteJumpEsquerda.size())
  {
     m_jump = 0;
  }

  QPixmap tam(spriteJumpEsquerda.at(m_jump));
  QPixmap aux = tam.scaled(100,100);
  setPixmap(aux);

  jump2->stop();
}

void Player::AtualizaRunDireita()
{
  Right->stop();
  run++;
  if(run == spriteRunDireita.size())
  {
     run = 0;
  }

  QPixmap tam(spriteRunDireita.at(run));
  QPixmap aux = tam.scaled(120,100);
  setPixmap(aux);
}

void Player::jump(int changeMode)
{
  if(changeMode == 1)
  {
      mode = 1;
  }
  else if(changeMode == 2)
  {
      mode = 2;
  }
  else if(changeMode == 3)
  {
      mode = 3;
  }

  if(parado == true){ // só pular quando estiver em algum chão (plataforma ou chão msm)
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sounds/sounds_jump.wav"));
    music->play();

    parado = false; //não está parado
    pula = true;   //pode pular
  }

}

void Player::spawn()
{
  Plataforma *plataforma;
  plataforma = new Plataforma();

  int random_number = rand() % 700;
  plataforma->setPos(random_number, 0);

  game->playwindow->scene->addItem(plataforma);

}

void Player::spawnPassaro()
{
  EnemyPassaro *passaro;
  passaro = new EnemyPassaro();

  int random_number = rand() % 700;
  passaro->setPos(0,random_number);

  game->playwindow->scene->addItem(passaro);

}

void Player::coins()
{
  Coin1 *coin1;
  coin1 = new Coin1();

  int random_number = rand() % 700;
  coin1->setPos(random_number, 0);

  game->playwindow->scene->addItem(coin1);

}

void Player::newJump(){

    if(pula == true && contador <= 25){    //Aqui so entra quando está livre para pular que é quando w é apertado
        if(contador < 5){   // se contador estiver logo no inicio o pulo seja mais rapido
           if(mode == 1)
           {
               this->setPos(x(),y()-10);
           }
           else if(mode == 2)
           {
               this->setPos(x()+3,y()-10);
           }
           else if(mode == 3)
           {
               this->setPos(x()-3,y()-10);
           }

        }
        else if(contador >= 5 && contador < 15){    //Aqui se o contador estiver ja mais avançado o pulo vai um  pouco mais devagar
                if(mode == 1)
                {
                    this->setPos(x(),y()-12);
                }
                else if(mode == 2)
                {
                    this->setPos(x()+3,y()-12);
                }
                else if(mode == 3)
                {
                    this->setPos(x()-3,y()-12);
                }
        }
        else if(contador >= 15 && contador <= 25){  //Aqui como já está no final do pulo vai mais devagar ainda
                if(mode == 1)
                {
                  this->setPos(x(),y()-5);
                }
                else if(mode == 2)
                {
                  this->setPos(x()+3,y()-5);
                }
                else if(mode == 3)
                {
                  this->setPos(x()-3,y()-5);
                }
            }


        if(contador == 25){ //quero que pare de pular
            pula = false;   //não pode mais pular
            parado = false; // ele caia (digo que não está em nenhuma superficie)
        }
        contador++;
    }
    else if(parado == false && contador <= 100){    //esta sequencia de ifs é a mesma coisa que antes para que caia mais lento depois mais rapido

        if(contador < 30){
            if(mode == 1)
            {
                this->setPos(x(),y()+5);
            }
            else if(mode == 2)
            {
                this->setPos(x()+3,y()+5);
            }
            else if(mode == 3)
            {
                this->setPos(x()-3,y()+5);
            }
        }
        else if(contador >= 30 && contador < 40){
                if(mode == 1)
                {
                    this->setPos(x(),y()+12);
                }
                else if(mode == 2)
                {
                    this->setPos(x()+3,y()+12);
                }
                else if(mode == 3)
                {
                    this->setPos(x()-3,y()+12);
                }
            }
            else if(contador >= 40){
                    if(mode == 1)
                    {
                        this->setPos(x(),y()+20);
                    }
                    else if(mode == 2)
                    {
                        this->setPos(x()+3,y()+20);
                    }
                    else if(mode == 3)
                    {
                        this->setPos(x()-3,y()+20);
                    }
                }

        if(pos().y() >= 770){   // se chegou no chão (superficie do jogo não nenhuma plataforma)
            this->setPos(x(),770);  //coloco ele na posição certa do chão
            parado = true;  // está na superficie não precisa mais cair
        }
        contador++;
    }
    else{ //se não está pulando
        contador = 0;
        parado = true;  //Esta em superficie
        pula = false;   //não é pra pular
    }
}

void Player::isSafe(bool status){   //modifica o atributo parado (para classes externas modificarem)
    parado = status;
}
