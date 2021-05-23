#include <QApplication>
#include "game.h"

extern Game *game;

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  a.setWindowIcon(QIcon(":/Images/arvore.png"));
  // criar novo jogo
  game = new Game();
  game->show();
  game->displayMenu();

  return a.exec();
}
