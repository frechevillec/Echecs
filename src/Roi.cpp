#include <iostream>
#include "Roi.h"
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

Roi::Roi(bool white) : Piece(5,(white?1:8),white) { }

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
  bool estValide = false;

  if ((abs(x - m_x)<= 1) && (abs(y - m_y) <= 1)){

      if(e.getPiece(x,y) != NULL){

          if(e.getPiece(x,y)->isWhite() != m_white){

              e.enleverPiece(x,y);
              cout << "mouvementValide de Roi" << endl;
              estValide = true;
          }

      } else {
          cout << "mouvementValide de Roi" << endl;
          estValide = true;
      }

      return estValide;
  }
}

char
Roi::type()
{
  return m_white ? 'R' : 'r';
}
