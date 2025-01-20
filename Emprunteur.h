#ifndef BIBLIO_EMPRUNTEUR_H
#define BIBLIO_EMPRUNTEUR_H

#include <iostream>
#include "Livre.h"
#include <vector>

using namespace std;

class Emprunteur
{
public:
    Emprunteur(int type);
    Emprunteur();

    int getType() const;

    const vector<Livre *> *getLivresEmpruntes() const;
    virtual string getNom();
    
    void afficheLivresEmpruntes();

protected:
    int type;
    vector<Livre *> livres_empruntes;
};

#endif
