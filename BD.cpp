#include "BD.h"
#include <iostream>
#include <string>
using namespace std;

BD::BD(int code, string auteur, string titre, string editeur, string isbn, string public_destine, string dessinateur)
    : Livre(code, auteur, titre, editeur, isbn, public_destine), dessinateur(dessinateur)
{
    this->type = Livre::BD;
}

BD::BD(const BD *bd) : Livre(bd->getCode(), bd->getAuteur(), bd->getTitre(), bd->getEditeur(), bd->getIsbn(), bd->public_destine), dessinateur(bd->getDessinateur())
{
    this->type = Livre::BD;
}

const string &BD::getDessinateur() const
{
    return dessinateur;
}

void BD::setDessinateur(const string &dessinateur)
{
    BD::dessinateur = dessinateur;
}

void BD::affiche()
{
    Livre::affiche();
    cout << " | Dessinateur : " << getDessinateur();
}
