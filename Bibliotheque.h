
#ifndef BIBLIO_BIBLIOTHEQUE_H
#define BIBLIO_BIBLIOTHEQUE_H

#include <iostream>

using namespace std;

#include "Emprunteur.h"
#include "Livre.h"
#include <vector>
class Adherent;

class Bibliotheque : public Emprunteur
{
public:
    Bibliotheque(const string &nom, const string &adresse, int code);

    const string &getNom() const;
    void setNom(const string &nom);
    const string &getAdresse() const;
    void setAdresse(const string &adresse);
    int getCode() const;
    const vector<Livre *> *getLivres() const;
    void addLivre(Livre *livre);
    void removeLivre(int);
    void affiche();
    void afficheLivres();
    Livre *emprunte(int, Emprunteur *);
    Livre *demande(Bibliotheque *, string);
    int getCodeFromISBN(string);
    void restitue(int);
    void addAdherent(Adherent &adherent);
    void afficheAdherents();

private:
    string nom;
    string adresse;
    int code;
    vector<Livre *> livres;
    vector<Adherent *> adherents;
    int nbLivres;

    Livre *getLivreFromCode(int);
};

#endif
