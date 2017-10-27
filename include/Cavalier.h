#ifndef CAVALIER_H
#define CAVALIER_H

#include "Piece.h"

class Cavalier : public Piece
{
public:
  Cavalier(bool white, bool left);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // CAVALIER_H
