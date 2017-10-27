#ifndef ROI_H
#define ROI_H

#include "Piece.h"

class Roi : public Piece
{
public:
  Roi(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // ROI_H
