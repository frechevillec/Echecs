#include <iostream>
#include "Piece.h"
#include "Pion.h"
#include "Echiquier.h"

using namespace std;

Pion::Pion(int x, bool white) : Piece(x, (white?2:7), white) { }

bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{
    bool estValide = false;

       if((m_y == 2 && m_white) || (m_y == 7 && !m_white))
       {

           if ((x == m_x && y == m_y+2 && m_white) || (x == m_x && y == m_y-2 && !m_white))
           {
               if (m_white && e.getPiece(m_x, m_y+1) == NULL && e.getPiece(m_x, m_y+2) == NULL)
               {
                   cout << "mouvementValide Pion." << endl;
                   estValide = true;
               }
               else
               {
                   if (!m_white && e.getPiece(m_x, m_y-1) == NULL && e.getPiece(m_x, m_y-2) == NULL)
                   {
                       cout << "mouvementValide Pion." << endl;
                       estValide = true;
                   }
               }
           }
           else
           {
               if ((x == m_x && y == m_y+1 && m_white) || (x == m_x && y == m_y-1 && !m_white))
               {
                   if(e.getPiece(x,y) == NULL)
                   {
                       cout << "mouvementValide Pion." << endl;
                       estValide = true;
                   }
               }
               else
               {
                   if((1 == abs(x-m_x) && y == m_y+1 && m_white) || (1 == abs(x-m_x) && y == m_y-1 && !m_white))
                   {
                       if (e.getPiece(x,y) != NULL && e.getPiece(x, y)->isWhite() != m_white)
                       {
                           e.enleverPiece(x,y);
                           cout << "mouvementValide Pion." << endl;
                           estValide = true;
                       }
                   }
               }
           }
       }
       else
       {
           if ((x == m_x && y == m_y+1 && m_white) || (x == m_x && y == m_y-1 && !m_white))
               {
                   if(e.getPiece(x,y) == NULL)
                   {
                       cout << "mouvementValide Pion." << endl;
                       estValide = true;
                   }
               }
               else
               {
                   if((1 == abs(x-m_x) && y == m_y+1 && m_white) || (1 == abs(x-m_x) && y == m_y-1 && !m_white))
                   {
                       if (e.getPiece(x,y) != NULL && e.getPiece(x, y)->isWhite() != m_white)
                       {
                           e.enleverPiece(x,y);
                           cout << "mouvementValide Pion." << endl;
                           estValide = true;
                       }
                   }
               }
       }

     return estValide;
}

char
Pion::type()
{
  return m_white ? 'P' : 'p';
}
