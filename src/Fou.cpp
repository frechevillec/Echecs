#include <iostream>
#include "Fou.h"
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

Fou::Fou() { }

Fou::Fou(bool white, bool left) : Piece((left?3:6),(white?1:8),white) { }

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{

    int xDepart = this->x(); //R�cup�ration du d�part de la pi�ce
    int yDepart = this->y();
    bool estBlanche = this->isWhite();
    bool estValide = false;
    int ecartX = x - xDepart;
    int ecartY = y - yDepart;

        //v�rifier si pi�ce sur chemin et v�rifier si pi�ce sur case d'arriv�e et sa couleur
      if (ecartX == ecartY || ecartX == -ecartY)   //pour aller en diagonale
        {
            if (ecartX > 0 && ecartY < 0)    //d�placement en haut � droite
            {
                while (xDepart != x && yDepart != y) //ET ou OU
                {
                    yDepart++;
                    yDepart--;

                    if (e.getPiece(yDepart,yDepart) != NULL)
                    {
                        if (xDepart == x && yDepart == y && e.getPiece(x,y)->isWhite() != estBlanche)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
                        {
                            e.enleverPiece(x,y);
                            cout << "mo" << endl;
                            estValide = true;
                        }
                    }
                    else
                    {
                        if(xDepart == x && yDepart == y && estValide == false)
                        {
                            cout << "Le mouvement du Fou est valide : d�placement Haut Droite" << endl;
                            estValide = true;
                        }
                    }
                }
            }
            else
            {
                if (ecartX < 0 && ecartY > 0)    //d�placement en bas � gauche
                {
                    while (xDepart != x && yDepart != y) //ET ou OU
                    {
                        xDepart--;
                        yDepart++;

                        if (e.getPiece(yDepart, yDepart) != NULL)
                        {
                            if (xDepart == x && yDepart == y && e.getPiece(x,y)->isWhite() != estBlanche)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
                            {
                                e.enleverPiece(x,y);
                                cout << "Le mouvement du Fou est valide : d�placement Bas Gauche" << endl;
                                estValide = true;
                            }
                        }
                        else
                        {
                            if(xDepart == x && yDepart == y && estValide == false)
                            {
                                cout << "Le mouvement du Fou est valide : d�placement Bas Gauche" << endl;
                                estValide = true;
                            }
                        }
                    }
                }
                else
                {
                    if(ecartX < 0 || ecartY < 0)    //d�placement haut gauche
                    {
                        while (xDepart != x || yDepart != y) //ET ou OU
                        {
                            xDepart--;
                            yDepart--;

                            if (e.getPiece(xDepart, yDepart) != NULL)
                            {
                                if (xDepart == x && yDepart == y && e.getPiece(x,y)->isWhite() != estBlanche)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
                                {
                                    e.enleverPiece(x,y);
                                    cout << "Le mouvement du Fou est valide : d�placement Haut Gauche" << endl;
                                    estValide = true;
                                }
                            }
                            else
                            {
                                if(xDepart == x && yDepart == y && estValide == false)
                                {
                                    cout << "Le mouvement du Fou est valide : d�placement Haut Gauche" << endl;
                                    estValide = true;
                                }
                            }
                        }
                    }
                    else            //d�placement bas droite
                    {
                        while (ecartX != x && ecartY != y) //ET ou OU
                        {
                            xDepart++;
                            yDepart++;

                            if (e.getPiece(xDepart, yDepart) != NULL)
                            {
                                if (xDepart == x && yDepart == y && e.getPiece(x,y)->isWhite() != estBlanche)   //Si pi�ce couleur joueur adverse alors on l'enl�ve !
                                {
                                    e.enleverPiece(x,y);
                                    cout << "Le mouvement du Fou est valide : d�placement Bas Droite" << endl;
                                    estValide = true;
                                }
                            }
                            else
                            {
                                if(xDepart == x && yDepart == y && estValide == false)
                                {
                                    cout << "Le mouvement du Fou est valide : d�placement Bas Droite" << endl;
                                    estValide = true;
                                }
                            }
                        }
                    }
                }
            }
        }
      return estValide;
    cout << "mouvementValide de Fou" << endl;
  return false;
}

char
Fou::type()
{
  return m_white ? 'F' : 'f';
}
