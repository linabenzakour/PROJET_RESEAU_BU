#include "../headers/Adherent.h"
#include "../headers/Bibliotheque.h"
#include <iostream>
#include <string>
using namespace std;

Adherent::Adherent(const string &nom, const string &prenom, const string &adresse, int num_adherent, Bibliotheque *bibliotheque, int autorisation_emprunt) 
: Emprunteur(0), nom(nom), prenom(prenom), adresse(adresse), num_adherent(num_adherent), bibliotheque(bibliotheque),autorisation_emprunt(autorisation_emprunt) {}

const string &Adherent::getNom() const
{
    return nom;
}

void Adherent::setNom(const string &nom)
{
    Adherent::nom = nom;
}

const string &Adherent::getPrenom() const
{
    return prenom;
}

void Adherent::setPrenom(const string &prenom)
{
    Adherent::prenom = prenom;
}

const string &Adherent::getAdresse() const
{
    return adresse;
}

void Adherent::setAdresse(const string &adresse)
{
    Adherent::adresse = adresse;
}

Bibliotheque *Adherent::getBibliotheque() const
{
    return bibliotheque;
}

void Adherent::setBibliotheque(Bibliotheque *bibliotheque)
{
    Adherent::bibliotheque = bibliotheque;
}

int Adherent::getAutorisationEmprunt() const
{
    return autorisation_emprunt;
}

void Adherent::setAutorisationEmprunt(int autorisation_emprunt)
{
    Adherent::autorisation_emprunt = autorisation_emprunt;
}

int Adherent::getNum_adherent() const
{
    return num_adherent;
}

void Adherent::emprunte(int code)
{
    if (livres_empruntes.size() >= getAutorisationEmprunt())
    {
        cout << "Cet adhérent a déjà trop de livres..." << endl;
        return;
    }
    Livre *l = bibliotheque->emprunte(code, this);
    if (l != nullptr)
    {
        livres_empruntes.push_back(l);
    }
}

void Adherent::restitue(int code)
{
    bool found = false;
    int num = 0;
    for (auto i = 0; i < livres_empruntes.size(); i++)
    {
        if (livres_empruntes[i]->getCode() == code)
        {
            found = true;
            num = i;
        }
    }

    if (!found)
    {
        cout << "Un problème a été rencontré : l'adhérent n'a pas emprunté ce livre, veuillez réessayer !" << endl;
        return;
    }

    livres_empruntes.erase(livres_empruntes.begin() + num);
    bibliotheque->restitue(code);
}

void Adherent::affiche()
{
    cout << "Adherent : " << getPrenom() << " " << getNom() << " | Adresse : " << getAdresse()<< " | Bilbliotheque : " << getBibliotheque()->getNom() << " | Livres : " << livres_empruntes.size() << "/" << getAutorisationEmprunt();

}
