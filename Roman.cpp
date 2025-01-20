#include "Roman.h"
#include <iostream>
#include <string>

using namespace std;

Roman::Roman(int code, string auteur, string titre, string editeur, string isbn, string public_destine, string genre)
: Livre(code, auteur, titre, editeur, isbn, public_destine)
{
    this->genre = genre;
    this->type = Livre::ROMAN;
}

Roman::Roman(const Roman *roman) : Livre(roman->getCode(), roman->getAuteur(), roman->getTitre(), roman->getEditeur(), roman->getIsbn(), roman->public_destine), genre(roman->getGenre())
{
    this->type = Livre::ROMAN;
}

const string &Roman::getGenre() const
{
    return genre;
}

void Roman::setGenre(const string &genre)
{
    Roman::genre = genre;
}

void Roman::affiche()
{
    Livre::affiche();
    cout << " | Genre :" << getGenre() << endl;
}