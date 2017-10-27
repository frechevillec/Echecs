#include <iostream>
#include "Piece.h"
#include "Cavalier.h"
#include "Echiquier.h"

using namespace std;

Cavalier::Cavalier(bool white, bool left) : Piece((left?2:7),(white?1:8),white) { }

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{

  bool estValide = false;

  if(abs(x - m_x) == 2 && abs(y - m_y) == 1 || (abs(x - m_x) == 1 && abs(y - m_y) == 2)){

      if(e.getPiece(x, y) != NULL){

          if(e.getPiece(x, y)->isWhite() != m_white) {
              e.enleverPiece(x,y);
              cout << "mouvementValide de Cavalier" << endl;
              estValide = true;

          }
      } else {

          cout << "mouvementValide de Cavalier" << endl;
          estValide = true;

      }
  }

  return estValide;
}

char
Cavalier::type()
{
  return m_white ? 'C' : 'c';
}
