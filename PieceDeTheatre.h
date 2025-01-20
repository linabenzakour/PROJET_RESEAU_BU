#ifndef BIBLIOTHEQUECPP_PIECEDETHEATRE_H
#define BIBLIOTHEQUECPP_PIECEDETHEATRE_H
#include "Livre.h"
#include <iostream>

using namespace std;

class PieceDeTheatre : public Livre
{
private:
    int siecle;

public:
    PieceDeTheatre(int code, string auteur, string titre, string editeur, string isbn, string public_destine, int siecle);
    PieceDeTheatre(const PieceDeTheatre *);
    void affiche();
    int getSiecle() const;
    void setSiecle(int siecle);
};
#endif