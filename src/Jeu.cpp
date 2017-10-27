#include <iostream>
#include <string>
#include "Jeu.h"
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include "Pion.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Reine.h"
#include "Roi.h"

using namespace std;

Jeu::Jeu()
{
    cout << "Constructeur Jeu defaut" << endl;
}

Jeu::~Jeu(){
    cout <<"Destructeur Partie" << endl;
}

void Jeu::verifCoordonnees(){

        while(true)
        {
            cout << "\nX = ";
            cin >> x;
            cout << "\nY = ";
            cin >> y;

            if((x>=1) && (x<=8) && (y>=1) && (y<=8))
            {
                break;
            }
            else
            {
                cout << "\nCoordonnees incorrectes. Ressaisissez les valeurs :";
            }
        }
}


int Jeu::isEnEchecAdv()
{
    int caseEchec = -1;
    int rbX, rbY, rnX, rnY;


    for (int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(e.getPiece(i, j) != NULL)
            {
                //On vérifie si la pièce est un roi
                if (e.getPiece(i, j)->type() == 'R')
                {
                    rbX = i;
                    rbY = j;
cout << "\n" << rbX;
cout << "\n" << rbY;
                }
                else
                {
                    if (e.getPiece(i, j)->type() == 'r')
                    {
                        rnX = i;
                        rnY = j;
                    }
                }
            }
        }
    }


    for (int k = 1; k <= 8; k++){
        for(int l = 1; l <= 8; l++){
            if(e.getPiece(k, l) != NULL)
            {
cout << "\n TEST 1";
                if (joueurActuel) //joueur blanc
                {
cout << "\n TEST 2";
                    if(e.getPiece(k, l)->isWhite())
                    {
                        if(e.getPiece(k, l)->mouvementValide(e, rnX, rnY))
                        {
                            caseEchec = 2;


                            for (int m = rnX-1 ; rnX+1 ; rnX++)
                            {
                                for (int n = rnY-1; rnY+1; rnY++)
                                {
                                    if (e.getPiece(rnX,rnY)->mouvementValide(e, m, n))
                                    {
                                        caseEchec = 3;
                                        goto fin;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if(e.getPiece(k, l)->mouvementValide(e, rbX, rbY))
                    {
                        caseEchec = 2;

                        for (int m = rnX-1 ; rnX+1 ; rnX++)
                        {
                            for (int n = rnY-1; rnY+1; rnY++)
                            {
                                if (e.getPiece(rnX,rnY)->mouvementValide(e, m, n))
                                {
                                    caseEchec = 3;
                                    goto fin;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

fin:
    return (caseEchec);
}


void Jeu::jouer()
{
    joueurActuel = true;
    bool mouvementValide = false;
    int isEnEchec = 0;
    bool partieFinie = false;
    int xDep;
    int yDep;
    char typePiece;

    jb.affiche();
    jn.affiche();

    jb.placerPieces(e);
    jn.placerPieces(e);

    /* On crée les pieces*/
  Roi rb(true);
  Roi rn(false);
  Reine qb(true);
  Reine qn(false);
  Tour tb1(true, true);
  Tour tn1(false, true);
  Tour tb2(true, false);
  Tour tn2(false, false);
  Fou fb1(true, true);
  Fou fn1(false, true);
  Fou fb2(true, false);
  Fou fn2(false, false);
  Cavalier cb1(true, true);
  Cavalier cn1(false, true);
  Cavalier cb2(true, false);
  Cavalier cn2(false, false);
  Pion pb1(1, true);
  Pion pn1(1, false);
  Pion pb2(2, true);
  Pion pn2(2, false);
  Pion pb3(3, true);
  Pion pn3(3, false);
  Pion pb4(4, true);
  Pion pn4(4, false);
  Pion pb5(5, true);
  Pion pn5(5, false);
  Pion pb6(6, true);
  Pion pn6(6, false);
  Pion pb7(7, true);
  Pion pn7(7, false);
  Pion pb8(8, true);
  Pion pn8(8, false);

/*On place les pieces*/
  e.enleverPiece(5,1);
  e.placer(&rb);
  e.enleverPiece(5,8);
  e.placer(&rn);
  e.enleverPiece(4,1);
  e.placer(&qb);
  e.enleverPiece(4,8);
  e.placer(&qn);
  e.enleverPiece(1,1);
  e.placer(&tb1);
  e.enleverPiece(1,8);
  e.placer(&tn1);
  e.enleverPiece(8,1);
  e.placer(&tb2);
  e.enleverPiece(8,8);
  e.placer(&tn2);
  e.enleverPiece(3,1);
  e.placer(&fb1);
  e.enleverPiece(3,8);
  e.placer(&fn1);
  e.enleverPiece(6,1);
  e.placer(&fb2);
  e.enleverPiece(6,8);
  e.placer(&fn2);
  e.enleverPiece(2,1);
  e.placer(&cb1);
  e.enleverPiece(2,8);
  e.placer(&cn1);
  e.enleverPiece(7,1);
  e.placer(&cb2);
  e.enleverPiece(7,8);
  e.placer(&cn2);
  e.enleverPiece(1,2);
  e.placer(&pb1);
  e.enleverPiece(1,7);
  e.placer(&pn1);
  e.enleverPiece(2,2);
  e.placer(&pb2);
  e.enleverPiece(2,7);
  e.placer(&pn2);
  e.enleverPiece(3,2);
  e.placer(&pb3);
  e.enleverPiece(3,7);
  e.placer(&pn3);
  e.enleverPiece(4,2);
  e.placer(&pb4);
  e.enleverPiece(4,7);
  e.placer(&pn4);
  e.enleverPiece(5,2);
  e.placer(&pb5);
  e.enleverPiece(5,7);
  e.placer(&pn5);
  e.enleverPiece(6,2);
  e.placer(&pb6);
  e.enleverPiece(6,7);
  e.placer(&pn6);
  e.enleverPiece(7,2);
  e.placer(&pb7);
  e.enleverPiece(7,7);
  e.placer(&pn7);
  e.enleverPiece(8,2);
  e.placer(&pb8);
  e.enleverPiece(8,7);
  e.placer(&pn8);

/*On lance la partie*/
    while(partieFinie == false)
    {
        bool mouvementValide = false;
        int isEnEchec = -1;
        e.affiche();

        /*On saisie les coordonnées*/
        if (joueurActuel)
        {
            cout << "\nAu tour du joueur blanc." << endl << "Choisissez les coordonnees de la piece a deplacer.";
        }
        else
        {
            cout << "\nAu tour du joueur noir." << endl << "Choisissez les coordonnees de la piece a deplacer.";
        }

        while(!mouvementValide)
        {
            this->verifCoordonnees();
            xDep = this->x;
            yDep = this->y;

            /*On verifie que la piece existe*/
                if (e.getPiece(xDep, yDep) != NULL)
                {
                    if ((joueurActuel && e.getPiece(xDep, yDep)->isWhite()) || (!joueurActuel && e.getPiece(xDep, yDep)->isBlack()))
                    {
                        while(!mouvementValide)
                        {
                            cout << "\nChoisissez les coordonnees ou vous souhaitez deplacer la piece : ";
                            verifCoordonnees();
                            if(e.getPiece(xDep,yDep)->mouvementValide(e, x, y))
                            {
                                /*On verifie si le roi est en echec*/
                                switch(yaEchec)
                                {
                                    case 1 :
                                        cout << "\nDeplacement Invalide : Vous etes en Echec si vous déplacez cette pièce.";
                                        break;
                                    case 2 :
                                        if (joueurActuel == true)
                                        {
                                            cout << "\nRoi du Joueur Noir en Echec.";
                                        }
                                        else
                                        {
                                            cout << "\nRoi du Joueur Blanc en Echec.";
                                        }
                                        e.deplacer(e.getPiece(xDep, yDep), x, y);
                                        mouvementValide = true;
                                        break;
                                    case 3 :
                                        if (joueurActuel == true)
                                        {
                                            cout << "\nRoi du Joueur Noir en Echec et Mat.";
                                        }
                                        else
                                        {
                                            cout << "\nRoi du Joueur Blanc en Echec et Mat.";
                                        }
                                        e.deplacer(e.getPiece(xDep, yDep), x, y);
                                        mouvementValide = true;
                                        partieFinie = true;
                                        break;
                                    default:
                                        e.deplacer(e.getPiece(xDep, yDep), x, y);
                                        mouvementValide = true;
                                        break;
                                }
                            }
                            else
                            {
                                cout << "\nMouvement impossible.";
                            }
                        }
                    }
                    else
                    {
                        cout << "\nCette piece n'est pas a vous. Choisissez de nouvelles coordonnees :";
                    }
                }
                else
                {
                    cout << "\nIl n'y a pas de piece a la position (" << xDep << "," << yDep << ")." << endl << "Choisissez de nouvelles coordonnees :";
                }

        }

        joueurActuel = !joueurActuel;   //changement de joueur

    }
}
