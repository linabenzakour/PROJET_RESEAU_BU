#include "Poesie.h"

#include <iostream>
#include <string>

using namespace std;

Poesie::Poesie(int code, string auteur, string titre, string editeur, string isbn,string public_destine, string style)
        : Livre(code, auteur, titre, editeur, isbn, public_destine) {
    this->style = style;
    this->type = Livre::POESIE;
}

Poesie::Poesie(const Poesie* poesie) : Livre(poesie->getCode(), poesie->getAuteur(), poesie->getTitre(), poesie->getEditeur(), poesie->getIsbn(), poesie->public_destine), style(poesie->getStyle())
{
    this->type = Livre::POESIE;
}

const string &Poesie::getStyle() const {
    return style;
}

void Poesie::setStyle(const string &style) {
    Poesie::style = style;
}

void Poesie::affiche() {
    Livre::affiche();
    cout<<" | Style :" << getStyle() <<endl;
}