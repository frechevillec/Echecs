#ifndef PION_H
#define PION_H

#include "Piece.h"

class Pion : public Piece
{
public:
  Pion(int x, bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // PION_H
