#include "Album.h"
#include <iostream>
#include <string>


using namespace std;

Album::Album(int code, string auteur, string titre, string editeur, string isbn,string public_destine, string illustrations)
        : Livre(code, auteur, titre, editeur, isbn, public_destine) {
    this->illustrations = illustrations;
    this->type = Livre::ALBUM;

}

Album::Album(const Album* album) : Livre(album->getCode(), album->getAuteur(), album->getTitre(), album->getEditeur(), album->getIsbn(), album->public_destine), illustrations(album->getIllustrations())
{
    this->type = Livre::ALBUM;
}


const string &Album::getIllustrations() const {
    return illustrations;
}

void Album::setIllustrations(const string &illustrations) {
    Album::illustrations = illustrations;
}

void Album::affiche() {
    Livre::affiche();
    cout << " | Type d'illustrations :" << getIllustrations() << endl;
}