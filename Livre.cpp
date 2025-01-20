#include "Livre.h"
#include "Emprunteur.h"
#include "Adherent.h"
#include "Album.h"
#include <iostream>
#include <string>
using namespace std;

Livre::Livre(int code, const string &auteur, const string &titre, const string &editeur, const string &isbn,const string &public_destine) : code(code), auteur(auteur), titre(titre), editeur(editeur), isbn(isbn),public_destine(public_destine)
{
    emprunte_par = nullptr;
    type = Livre::LIVRE;
}

Livre::Livre()
{
    emprunte_par = nullptr;
    type = Livre::LIVRE;
}

Livre::Livre(Livre *l) : code(l->getCode()), auteur(l->getAuteur()), titre(l->getTitre()), editeur(l->getEditeur()), isbn(l->getIsbn()), public_destine(l->getPublic_destine())
{
    emprunte_par = nullptr;
    type = Livre::LIVRE;
}

int Livre::getType() const
{
    return type;
}

int Livre::getCode() const
{
    return code;
}

const string &Livre::getAuteur() const
{
    return auteur;
}

void Livre::setAuteur(const string &auteur)
{
    Livre::auteur = auteur;
}

const string &Livre::getTitre() const
{
    return titre;
}

void Livre::setTitre(const string &titre)
{
    Livre::titre = titre;
}

const string &Livre::getEditeur() const
{
    return editeur;
}

void Livre::setEditeur(const string &editeur)
{
    Livre::editeur = editeur;
}

const string &Livre::getIsbn() const
{
    return isbn;
}

void Livre::setIsbn(const string &isbn)
{
    Livre::isbn = isbn;
}

const string &Livre::getPublic_destine() const
{
    return public_destine;
}

void Livre::setPublic_destine(const string &public_destine)
{
    Livre::public_destine = public_destine;
}

Emprunteur *Livre::getEmprunte_par() const
{
    return emprunte_par;
}

void Livre::setEmprunte_par(Emprunteur *emprunte_par)
{
    Livre::emprunte_par = emprunte_par;
}

void Livre::restitue()
{
    Livre::emprunte_par = nullptr;
}

void Livre::affiche()
{
    cout << "Titre : " << getTitre() << " | Auteur : " << getAuteur()<< " | Editeur : " << editeur<< " | Public : " << public_destine<< " | ISBN : " << isbn<< " | Dispo : ";
    if (emprunte_par != nullptr)
    {
        if (emprunte_par->getType() == 0)
        {
            Adherent *adherent = dynamic_cast<Adherent *>(emprunte_par);
            cout << "Emprunté par l'adhérent" << adherent->getNom() << "  " << adherent->getPrenom();
        }
        else if (emprunte_par->getType() == 1)
        {
            Bibliotheque *biblio = dynamic_cast<Bibliotheque *>(emprunte_par);
            cout << "Emprunté par la biblio :  " << biblio->getNom();
        }
    }
    else
    {
        cout << "Disponible";
    }
}

void Livre::setIllustrations(const string &illustrations) {}