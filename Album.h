#ifndef BIBLIOTHEQUECPP_ALBUM_H
#define BIBLIOTHEQUECPP_ALBUM_H

#include "Livre.h"
#include <iostream>

using namespace std;

class Album : public Livre
{
private:
    string illustrations;

public:
    Album(int code, string auteur, string titre, string editeur, string isbn,
          string public_destine, string illustrations);
    Album(const Album *);
    void affiche();
    const string &getIllustrations() const;
    void setIllustrations(const string &illustrations);
};
#endif