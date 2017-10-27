#ifndef JOUEURBLANC_H
#define JOUEURBLANC_H

#include "Joueur.h"

class JoueurBlanc : public Joueur {
public:
        JoueurBlanc();
        ~JoueurBlanc();

        bool isWhite();
        bool isBlack();
};

#endif // JOUEURBLANC_H
