#include "Emprunteur.h"
#include <iostream>
using namespace std;

Emprunteur::Emprunteur(int type) : type(type) {}
Emprunteur::Emprunteur() {}
int Emprunteur::getType() const
{
    return type;
}

const vector<Livre *> *Emprunteur::getLivresEmpruntes() const
{
    return &livres_empruntes;
}

string Emprunteur::getNom()
{
    return "";
}

void Emprunteur::afficheLivresEmpruntes()
{
    cout << "Livres empruntés : " << endl;
    for (auto i = 0; i < livres_empruntes.size(); i++)
    {
        cout << i + 1 << "  -  ";
        livres_empruntes[i]->affiche();
        cout << endl;
    }
}