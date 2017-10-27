#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"
#include "Pion.h"
#include "Cavalier.h"
#include "Roi.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"

class Joueur
{
private:
    Piece *m_pieces[16];

public:
    Joueur();
    ~Joueur();

    void init( bool white );
    void affiche();
    bool placerPieces(Echiquier & e);
};


#endif // !defined Joueur_h
