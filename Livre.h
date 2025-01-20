#ifndef BIBLIO_LIVRE_H
#define BIBLIO_LIVRE_H
#include <iostream>
using namespace std;
class Emprunteur;
class Livre
{
public:
    Livre(int code, const string &auteur, const string &titre, const string &editeur, const string &isbn,const string &public_destine);

    Livre();
    Livre(Livre *);

    const string &getAuteur() const;
    void setAuteur(const string &auteur);
    const string &getTitre() const;
    void setTitre(const string &titre);
    const string &getEditeur() const;
    void setEditeur(const string &editeur);
    const string &getIsbn() const;
    void setIsbn(const string &isbn);
    const string &getPublic_destine() const;

    void setPublic_destine(const string &public_destine);
    int getCode() const;
    virtual void affiche();
    Emprunteur *getEmprunte_par() const;
    void setEmprunte_par(Emprunteur *emprunte_par);
    void restitue();
    int getType() const;
    virtual void setIllustrations(const string &illustrations);
    enum types
    {
        LIVRE,BD,ALBUM,POESIE,ROMAN,PIECE
    };

protected:
    int type;
    int code;
    string auteur;
    string titre;
    string editeur;
    string isbn;
    string public_destine;
    Emprunteur *emprunte_par;
};

#endif
