#ifndef JEU_H
#define JEU_H

#include "Piece.h"
#include "Echiquier.h"
#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include <string>

using namespace std;

class Jeu
{

  protected:
    Echiquier e;
    JoueurBlanc jb;
    JoueurNoir jn;
    bool joueurActuel;
    int x;
    int y;

public:
    Jeu();
    ~Jeu();
    void jouer();
    void verifCoordonnees();
    int YaEchecAdv();
};

#endif // JEU_H
