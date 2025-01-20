#ifndef BIBLIOTHEQUECPP_ROMAN_H
#define BIBLIOTHEQUECPP_ROMAN_H

#include "Livre.h"
#include <iostream>

using namespace std;

class Roman : public Livre
{
private:
    string genre;

public:
    Roman(int code, string auteur, string titre, string editeur, string isbn,string public_destine, string genre);
    Roman(const Roman *);
    void affiche();
    const string &getGenre() const;
    void setGenre(const string &genre);
};

#endif
