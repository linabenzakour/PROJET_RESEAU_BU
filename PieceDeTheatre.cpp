#include "PieceDeTheatre.h"

#include <iostream>
#include <string>

using namespace std;

PieceDeTheatre::PieceDeTheatre(int code, string auteur, string titre, string editeur, string isbn, string public_destine, int siecle)
    : Livre(code, auteur, titre, editeur, isbn, public_destine), siecle(siecle)
{
    this->type = Livre::PIECE;
}

PieceDeTheatre::PieceDeTheatre(const PieceDeTheatre *pdt) : Livre(pdt->getCode(), pdt->getAuteur(), pdt->getTitre(), pdt->getEditeur(), pdt->getIsbn(), pdt->public_destine), siecle(pdt->getSiecle())
{
    this->type = Livre::PIECE;
}

int PieceDeTheatre::getSiecle() const
{
    return siecle;
}

void PieceDeTheatre::setSiecle(int siecle)
{
    PieceDeTheatre::siecle = siecle;
}

void PieceDeTheatre::affiche()
{
    Livre::affiche();
    cout << " | Siècle d'écriture :" << getSiecle() << endl;
}