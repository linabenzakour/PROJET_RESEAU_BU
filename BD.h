#ifndef BIBLIO_BD_H
#define BIBLIO_BD_H
#include "Livre.h"
#include <iostream>

using namespace std;

class BD : public Livre
{
public:
    BD(int code, string auteur, string titre, string editeur, string isbn, string public_destine,string dessinateur);
    BD(const BD *);
    void affiche();
    const string &getDessinateur() const;
    void setDessinateur(const string &dessinateur);

private:
    string dessinateur;
};

#endif
