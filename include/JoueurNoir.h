#ifndef JOUEURNOIR_H
#define JOUEURNOIR_H

#include "Joueur.h"

class JoueurNoir : public Joueur {
public:
        JoueurNoir();
        ~JoueurNoir();

        bool isWhite();
        bool isBlack();
};

#endif // JOUEURNOIR_H
