#ifndef BIBLIOTHEQUECPP_POESIE_H
#define BIBLIOTHEQUECPP_POESIE_H
#include "Livre.h"
#include <iostream>
using namespace std;

class Poesie : public Livre
{
private:
    string style;
public:
    Poesie(int code, string auteur, string titre, string editeur, string isbn,string public_destine, string style);
    Poesie(const Poesie *);
    void affiche();
    const string &getStyle() const;
    void setStyle(const string &style);
};

#endif
