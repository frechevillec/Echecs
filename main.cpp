/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "Pion.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Tour.h"
#include "Reine.h"
#include "Roi.h"
#include "JoueurNoir.h"
#include "JoueurBlanc.h"
#include "Jeu.h"


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
 * Programme principal
 */
int main( int argc, char** argv )
{

  Jeu j;
  j.jouer();

}
