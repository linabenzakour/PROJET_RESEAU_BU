#include <iostream>
#include <string>
#include <vector>
#include "headers/Livre.h"
#include "headers/BD.h"
#include "headers/Bibliotheque.h"
#include "headers/Poesie.h"
#include "headers/PieceDeTheatre.h"
#include "headers/Adherent.h"
#include "headers/Album.h"

using namespace std;

// Nos fonctions principales:
void afficherMenuPrincipal();
void donneesTests();
void donneesInitiales();
void afficherMessageTitre(string);

vector<Bibliotheque> biblios;

int main()
{
    afficherMessageTitre(" BENZAKOUR Lina et BARNY Julie vous présente leur réseau de bibliotheques : ");
    afficherMenuPrincipal();
    return 0;
}

void afficherMenuPrincipal()
// Nous avons eu l'idée de faire une intéraction avec l'utilisateur par un menu. cela va permettre de mettre à jour les données si l'utilisateur modifie la fonction main
{
    bool continuer = true;
    int choix = 0;
    do
    {
        cout << " ---- Menu de la gestion du notre réseau de bibliothèque ----" << endl;
        cout << "Présentation de nos bibliothèque et de leurs ouvrages : taper 1 " << endl;
        /*cout << "Afficher la liste des bibliotheques et leur ouvrage : taper 2 " << endl;*/
        cout << "Gerer le réseau des biliothèques : taper 2" << endl;
        cout << "Veillez tapez votre choix : ";
        cin >> choix;

        switch (choix)
        {
        case 1:
            donneesInitiales();
            break;

        case 2:
            donneesTests();
            break;

        default:
            cout << endl
                 << "Votre choix n'est pas validé." << endl;
        }
        cout << endl;
    } while (continuer);
}

void donneesInitiales()
// On initialise les BU et leurs ouvrages 

{

    Livre livre1 = Livre(101, "Victor Hugo", "Les Misérables", "Paris", "9782070418056", "Classique");
    BD bd1 = BD(102, "Albert Uderzo", "Astérix chez les Bretons", "Paris", "9782012101435", "Humour", "Illust. Uderzo");
    PieceDeTheatre piece1 = PieceDeTheatre(103, "Molière", "Le Malade Imaginaire", "Paris", "9782070369426", "Théâtre", 1673);
    Poesie poesie1 = Poesie(104, "Charles Baudelaire", "Les Fleurs du mal", "Paris", "9782253137602", "Poésie", "Vers classiques");
    Livre livre = Livre(103, "George Orwell", "1984", "Londres", "9780451524935", "Dystopie");


    // biblio 1
    Bibliotheque BNF = Bibliotheque("Bibliothèque nationale de France", "Quai François Mauriac", 75013);
    BNF.addLivre(&livre1);
    BNF.addLivre(&bd1);
    BNF.addLivre(&piece1);
    BNF.addLivre(&poesie1);

    Livre livre2 = Livre(201, "Jules Verne", "Vingt Mille Lieues sous les Mers", "Nantes", "9782253003013", "Science-fiction");
    BD bd2 = BD(202, "René Goscinny", "Lucky Luke - La Caravane", "Paris", "9782884711245", "Western", "Illust. Morris");
    PieceDeTheatre piece2 = PieceDeTheatre(203, "Jean Racine", "Phèdre", "Paris", "9782070368191", "Théâtre", 1677);
    Poesie poesie2 = Poesie(204, "Arthur Rimbaud", "Illuminations", "Paris", "9782070300276", "Poésie", "Vers libres");

    // biblio 2
    Bibliotheque BPI = Bibliotheque("Bibliothèque publique d'information", "Rue Beaubourg", 75004);
    BPI.addLivre(&livre2);
    BPI.addLivre(&bd2);
    BPI.addLivre(&piece2);
    BPI.addLivre(&poesie2);

    Livre livre3 = Livre(301, "Albert Camus", "L'Étranger", "Alger", "9782070360027", "Philosophie");
    BD bd3 = BD(302, "Hergé", "Les Aventures de Tintin - Le Lotus bleu", "Bruxelles", "9782203001120", "Aventure", "Illust. Hergé");
    PieceDeTheatre piece3 = PieceDeTheatre(303, "William Shakespeare", "Hamlet", "London", "9782070360010", "Tragédie", 1603);
    Poesie poesie3 = Poesie(304, "Paul Verlaine", "Poèmes Saturniens", "Paris", "9782070361116", "Poésie", "Vers mélancoliques");

    // biblio 3
    Bibliotheque BSG = Bibliotheque("Bibliothèque Sainte-Geneviève", "Place du Panthéon", 75005);
    BSG.addLivre(&livre3);
    BSG.addLivre(&bd3);
    BSG.addLivre(&piece3);
    BSG.addLivre(&poesie3);

    Livre livre4 = Livre(401, "Marie Curie", "Découverte de la radioactivité", "Paris", "978312345601", "Science");
    BD bd4 = BD(402, "Albert Einstein", "La Relativité en BD", "Paris", "978312345602", "Science", "Illust. Feynman");
    PieceDeTheatre piece4 = PieceDeTheatre(403, "William Shakespeare", "Hamlet", "London", "978312345603", "Classique", 159);
    Poesie poesie4 = Poesie(404, "Baudelaire", "Les Fleurs du mal", "Paris", "978312345604", "Poésie", "Vers classiques");

    // biblio 4
    Bibliotheque BibliothequeParis = Bibliotheque("Bibliothèque de Paris", "Rue de Rivoli", 75001);
    BibliothequeParis.addLivre(&livre4);
    BibliothequeParis.addLivre(&bd4);
    BibliothequeParis.addLivre(&piece4);
    BibliothequeParis.addLivre(&poesie4);

    // bibliothèques à la liste (nouvel élément à la fin du vecteur)
    biblios.push_back(BNF);
    biblios.push_back(BPI);
    biblios.push_back(BSG);
    biblios.push_back(BibliothequeParis);

    afficherMessageTitre("Nos bibliotheques : ");
    for (auto i = 0; i < biblios.size(); i++)
    {
        cout << "======================================= " << endl;
        biblios[i].affiche();
        cout << "======================================= " << endl;
    }
}


void donneesTests()
// avec cette fonction on peut tester pour visualiser l'ensemble des informations concernant le réseau de bibliothèque et sa gestion 
{

    Livre livre1 = Livre(101, "Victor Hugo", "Les Misérables", "Paris", "9782070418056", "Classique");
    BD bd1 = BD(102, "Albert Uderzo", "Astérix chez les Bretons", "Paris", "9782012101435", "Humour", "Illust. Uderzo");
    PieceDeTheatre piece1 = PieceDeTheatre(103, "Molière", "Le Malade Imaginaire", "Paris", "9782070369426", "Théâtre", 1673);
    Poesie poesie1 = Poesie(104, "Charles Baudelaire", "Les Fleurs du mal", "Paris", "9782253137602", "Poésie", "Vers classiques");
    Livre livre = Livre(103, "George Orwell", "1984", "Londres", "9780451524935", "Dystopie");

    // biblio 1
    Bibliotheque BNF = Bibliotheque("Bibliothèque nationale de France", "Quai François Mauriac", 75013);
    BNF.addLivre(&livre1);
    BNF.addLivre(&bd1);
    BNF.addLivre(&piece1);
    BNF.addLivre(&poesie1);
    BNF.addLivre(&livre);

    // aherent
    Adherent adherentBNF1 = Adherent("BENZAKOUR", "Lina", "20 Rue Albert Roussel 75017 Paris", 1, &BNF, 2);
    BNF.addAdherent(adherentBNF1);

    Livre livre2 = Livre(201, "Jules Verne", "Vingt Mille Lieues sous les Mers", "Nantes", "9782253003013", "Science-fiction");
    BD bd2 = BD(202, "René Goscinny", "Lucky Luke - La Caravane", "Paris", "9782884711245", "Western", "Illust. Morris");
    PieceDeTheatre piece2 = PieceDeTheatre(203, "Jean Racine", "Phèdre", "Paris", "9782070368191", "Théâtre", 1677);
    Poesie poesie2 = Poesie(204, "Arthur Rimbaud", "Illuminations", "Paris", "9782070300276", "Poésie", "Vers libres");

    // biblio 2
    Bibliotheque BPI = Bibliotheque("Bibliothèque publique d'information", "Rue Beaubourg", 75004);
    BPI.addLivre(&livre2);
    BPI.addLivre(&bd2);
    BPI.addLivre(&piece2);
    BPI.addLivre(&poesie2);

    Adherent adherentBPI1 = Adherent("BARNY", "Julie", "38 Rue Frédéric Joliot Curie, 13013 Marseille", 1, &BPI, 2);
    BPI.addAdherent(adherentBPI1);

    Livre livre3 = Livre(301, "Albert Camus", "L'Étranger", "Alger", "9782070360027", "Philosophie");
    BD bd3 = BD(302, "Hergé", "Les Aventures de Tintin - Le Lotus bleu", "Bruxelles", "9782203001120", "Aventure", "Illust. Hergé");
    PieceDeTheatre piece3 = PieceDeTheatre(303, "William Shakespeare", "Hamlet", "London", "9782070360010", "Tragédie", 1603);
    Poesie poesie3 = Poesie(304, "Paul Verlaine", "Poèmes Saturniens", "Paris", "9782070361116", "Poésie", "Vers mélancoliques");

    // biblio 3
    Bibliotheque BSG = Bibliotheque("Bibliothèque Sainte-Geneviève", "Place du Panthéon", 75005);
    BSG.addLivre(&livre3);
    BSG.addLivre(&bd3);
    BSG.addLivre(&piece3);
    BSG.addLivre(&poesie3);

    Adherent adherentBSG1 = Adherent("BELGROUN", "Adel", "6 Rue Louis Néel 13013 Marseille", 1, &BPI, 2);
    BSG.addAdherent(adherentBSG1);

    /*
        Livre livre4 = Livre(401, "Marie Curie", "Découverte de la radioactivité", "Paris", "978312345601", "Science");
        BD bd4 = BD(402, "Albert Einstein", "La Relativité en BD", "Paris", "978312345602", "Science", "Illust. Feynman");
        PieceDeTheatre piece4 = PieceDeTheatre(403, "William Shakespeare", "Hamlet", "London", "978312345603", "Classique", 159);
        Poesie poesie4 = Poesie(404, "Baudelaire", "Les Fleurs du mal", "Paris", "978312345604", "Poésie", "Vers classiques");

        // biblio 4
        Bibliotheque BibliothequeParis = Bibliotheque("Bibliothèque de Paris", "Rue de Rivoli", 75001);
        BibliothequeParis.addLivre(&livre4);
        BibliothequeParis.addLivre(&bd4);
        BibliothequeParis.addLivre(&piece4);
        BibliothequeParis.addLivre(&poesie4);

        // bibliothèques à la liste (nouvel élément à la fin du vecteur)
        biblios.push_back(BNF);
        biblios.push_back(BPI);
        biblios.push_back(BSG);
        biblios.push_back(BibliothequeParis);
    */

    afficherMessageTitre("Test des differentes possibilités dans nos bibliothèques");
    // PRÉSENTATION DES DIFFERENTES BIBLIOTHÈQUES
    cout << "----- Bibliotheque BNF, ses livres et ses adherents : -----" << endl;
    cout << endl<< endl;
    BNF.affiche();
    cout << endl<< endl;
    BNF.afficheLivres();
    cout << endl<< endl;
    BNF.afficheAdherents();
    cout << endl<< endl<< endl;

    cout << "----- Bibliotheque BPI, ses livres et ses adherents : -----" << endl;
    cout << endl<< endl;
    BPI.affiche();
    cout << endl<< endl;
    BPI.afficheLivres();
    cout << endl<< endl;
    BPI.afficheAdherents();
    cout << endl<< endl<< endl;

    cout << "----- Bibliotheque BSG, ses livres et ses adherents : -----" << endl;
    cout << endl<< endl;
    BSG.affiche();
    cout << endl << endl;
    BSG.afficheLivres();
    cout << endl<< endl;
    BSG.afficheAdherents();
    cout << endl<< endl << endl;

    cout << "----- Adherent de la BNF qui emprunte un livre : -----" << endl;
    cout << endl;

    adherentBNF1.emprunte(livre1.getCode()); 
    cout << endl<< endl;

    adherentBNF1.afficheLivresEmpruntes();
    cout << endl<< endl;

    BNF.afficheLivres();
    cout << endl<< endl<< endl;

    cout << "----- L'adherant veut resstitué le livre : -----" << endl;
    cout << endl;
    adherentBNF1.restitue(livre1.getCode());
    cout << endl;
    BNF.afficheLivres();
    cout << endl;
    BNF.afficheLivresEmpruntes();
    cout << endl<< endl;

    cout << "----- La BPI veut suprimer une piece : -----" << endl;
    cout << endl << endl;
    cout << "----- Avant suppression : " << piece2.getTitre() << endl;
    cout << endl;
    BPI.afficheLivres();
    cout << endl << endl;

    BPI.removeLivre(piece2.getCode());

    cout << "----- Après suppresion\n";
    cout << endl << endl;
    BPI.afficheLivres();
    cout << endl<< endl<< endl;

    cout << "----- La BSG veut emprunter une BD à la  BPI : -----" << endl;
    // LIMITE du titre 
    cout << endl << endl;
    cout << "----- Avant emprunt\n";
    cout << endl << endl;
    BSG.afficheLivres();
    cout << endl;
    BSG.demande(&BPI, "9782884711245");

    cout << "----- Après emprunt\n";
    cout << endl << endl;
    BPI.afficheLivres();
    cout << endl << endl;
    BSG.afficheLivres();
    cout << endl<< endl<< endl;

}

void afficherMessageTitre(const string titre)
// pour améliorer le visuel de l'interaction avec l'utilisateur sinon on se perd avec toutes les lignes de codes
{
    string decor(titre.size() + 6, '=');

    cout << decor << endl;
    cout << " " << titre << " " << endl;
    cout << " " << decor << " " << endl
         << endl;
}