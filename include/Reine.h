#ifndef REINE_H
#define REINE_H

#include "Piece.h"
#include "Fou.h"
#include "Tour.h"

class Reine : public Fou, public Tour
{
public:
  Reine(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // REINE_H
