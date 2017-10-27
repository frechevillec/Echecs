#ifndef FOU_H
#define FOU_H

#include "Piece.h"

class Fou : virtual public Piece
{
public:
  Fou();
  Fou(bool white, bool left);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // FOU_H
