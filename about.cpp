#include "about.h"

#include <QGraphicsRectItem>

About::About(QWidget *parent): QGraphicsView(parent)
{
  scene = new QGraphicsScene();

  setWindowIcon(QIcon(":/Images/info-button.png"));

  scene->setSceneRect(0, 0, 800, 950);
  scene->setBackgroundBrush(QBrush(QImage(":/Images/background.png")));

  setScene(scene);

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setFixedSize(800, 950);

  show();
}

void About::information()
{
  //create the name text
  QGraphicsTextItem * nome = new QGraphicsTextItem(QString("Nome: Fabiola Spredemann"));
  QFont nomeFont("karantina", 15);
  nome->setFont(nomeFont);

  int nomeX = 150;
  int nomeY = 250;

  nome->setPos(nomeX, nomeY);
  scene->addItem(nome);

  //create the matricula text
  QGraphicsTextItem * matricula = new QGraphicsTextItem(QString("Matrícula: 19104067"));
  QFont matFont("karantina", 15);
  matricula->setFont(matFont);

  int matX = 150;
  int matY = 300;

  matricula->setPos(matX, matY);
  scene->addItem(matricula);

  //create the photo item
  QGraphicsRectItem *foto = new QGraphicsRectItem(0,0,500,500);
  scene->addItem(foto);
  foto->setPos(150,350);
  foto->setBrush(QBrush(QImage(":/Images/foto.png")));
}

