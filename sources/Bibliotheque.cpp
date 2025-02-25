#include "../headers/Bibliotheque.h"
#include "../headers/Adherent.h"
#include "../headers/Livre.h"
#include "../headers/Emprunteur.h"
#include "../headers/Album.h"
#include "../headers/BD.h"
#include "../headers/PieceDeTheatre.h"
#include "../headers/Poesie.h"
#include "../headers/Roman.h"
#include <iostream>
#include <string>

using namespace std;

Bibliotheque::Bibliotheque(const string &nom, const string &adresse, int code) : Emprunteur(1), nom(nom), adresse(adresse), code(code) {}

const string &Bibliotheque::getNom() const
{
    return nom;
}

void Bibliotheque::setNom(const string &nom)
{
    Bibliotheque::nom = nom;
}

const string &Bibliotheque::getAdresse() const
{
    return adresse;
}

void Bibliotheque::setAdresse(const string &adresse)
{
    Bibliotheque::adresse = adresse;
}

int Bibliotheque::getCode() const
{
    return code;
}

const vector<Livre *> *Bibliotheque::getLivres() const
{
    return &livres;
}

void Bibliotheque::addLivre(Livre *livre)
{
    livres.push_back(livre);
}

void Bibliotheque::addAdherent(Adherent &adherent)
{
    adherents.push_back(&adherent);
}

void Bibliotheque::removeLivre(int code)
{
    bool found = false;
    int num = 0;
    for (auto i = 0; i < livres.size(); i++)
    {
        if (livres[i]->getCode() == code)
        {
            found = true;
            num = i;
        }
    }

    if (!found)
    {
        cout << "Livre introuvable" << endl;
    }

    livres.erase(livres.begin() + num);
}

void Bibliotheque::affiche()
{
    cout << "Bibliothèque " << getNom() << endl;
    cout << "Code : " << getCode() << " | Adresse : " << getAdresse() << endl;
}

void Bibliotheque::afficheLivres()
{
    cout << "Livre " << getNom() << " ( nombre d'ouvrages : " << livres.size() << ") : " << endl;
    for (auto i = 0; i < livres.size(); i++)
    {
        cout << i + 1 << "  -  ";
        livres[i]->affiche();
        cout << endl;
    }
}

void Bibliotheque::afficheAdherents()
{
    cout << "Adherents " << getNom() << " ( nombre d'ahdérents : "  << adherents.size() << ") : " << endl;
    for (auto i = 0; i < adherents.size(); i++)
    {
        cout << i + 1 << "  -  ";
        adherents[i]->affiche();
        cout << endl;
    }
}

Livre *Bibliotheque::getLivreFromCode(int code)
{
    bool found = false;
    int num = 0;
    for (auto i = 0; i < livres.size(); i++)
    {
        if (livres[i]->getCode() == code)
        {
            found = true;
            num = i;
        }
    }

    if (!found)
    {
        cout << "introuvable";
        return nullptr;
    }

    return livres[num];
}

Livre *Bibliotheque::emprunte(int code, Emprunteur *emprunteur)
{
    Livre *livre = getLivreFromCode(code);
    if (livre->getEmprunte_par() != nullptr)
    {
        cout << "Ce livre est deja emprunte" << endl;
        return nullptr;
    }

    livre->setEmprunte_par(emprunteur);
    return livre;
}

Livre *Bibliotheque::demande(Bibliotheque *biblio, string isbn)
{
    int code = biblio->getCodeFromISBN(isbn);
    if (code == -1)
    {
        cout << "La bibliotheque n'a pas ce livre." << endl;
        return nullptr;
    }

    Livre *l = biblio->emprunte(code, this);
    livres_empruntes.push_back(l);
    switch (l->getType())
    {
    case Livre::ALBUM:
    {
        Album *a = dynamic_cast<Album *>(l);
        Album *copie = new Album(a);
        copie->restitue();
        this->addLivre(copie);
        break;
    }
    case Livre::BD:
    {
        BD *b = dynamic_cast<BD *>(l);
        BD *copie = new BD(b);
        copie->restitue();
        this->addLivre(copie);
        break;
    }
    case Livre::PIECE:
    {
        PieceDeTheatre *p = dynamic_cast<PieceDeTheatre *>(l);
        PieceDeTheatre *copie = new PieceDeTheatre(p);
        copie->restitue();
        this->addLivre(copie);
    }
    case Livre::POESIE:
    {
        Poesie *p = dynamic_cast<Poesie *>(l);
        Poesie *copie = new Poesie(p);
        copie->restitue();
        this->addLivre(copie);
    }
    case Livre::ROMAN:
    {
        Roman *r = dynamic_cast<Roman *>(l);
        Roman *copie = new Roman(r);
        copie->restitue();
        this->addLivre(copie);
    }
    default:
        Livre *copie = new Livre(l);
        copie->restitue();
        this->addLivre(copie);
    }

    return l;
}

int Bibliotheque::getCodeFromISBN(string isbn)
{
    bool found = false;
    int code = -1;
    for (auto i = 0; i < livres.size(); i++)
    {
        if (livres[i]->getIsbn() == isbn)
        {
            found = true;
            code = livres[i]->getCode();
        }
    }

    return code;
}

void Bibliotheque::restitue(int code)
{
    Livre *livre = getLivreFromCode(code);
    if (livre->getEmprunte_par() == nullptr)
    {
        cout << "nonemprunte" << endl;
        return;
    }

    livre->restitue();
}


