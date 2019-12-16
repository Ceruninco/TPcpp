
/*************************************************************************
                           TrajetSimple  -  description
un TrajetSimple modélise un trajet simple constitué d'une ville de départ, d'une ville d'arrivée et d'un moyen de transport
On peut afficher ces informations et rechercher des correspondances avec des villes
                             -------------------
    début                : 18/11/19
    *************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Classe modélisant un trajet simple :
// possède une ville de départ, une ville d'arrivée et un moyen de transport
//
//------------------------------------------------------------------------

class TrajetSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
virtual string description_save();
virtual void afficher()const;
// Appelée par la méthode afficherTrajets de catalogue suite au menu avec l'entrée 3
//
// Affiche le contenu du trajet simple :  ville de départ, ville d'arrivée, moyen de transport
//

virtual int trajetCorrespond(char* villeDepart, char * villeArrivee)const;
// Appelée par la méthode rechercherTrajet de catalogue suite au menu avec l'entrée 4
//
// Compare les informations du trajet recherché avec celles du trajet simple (ville de départ et ville d'arrivée), renvoie 1 si celles ci correspondent
//

virtual char* villeFin()const;
// Renvoie la ville d'arrivée du trajet simple
//

virtual int tailleTrajet()const;
// Renvoie la taille du trajet, soit 1 car c'est un trajet simple
//


char* getVilleDepart()const;
// Renvoie la ville de départ du trajet simple
//


char* getMoyenTransport()const;
// Renvoie le moyen de transport du trajet simple
//


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple ( const TrajetSimple & unTrajetSimple );
// copie les informations de unTrajetSimple
//

TrajetSimple (char * vilDep, char *  vilArr, char *  moyenT);
// Appelé au menu par l'entrée 1 pour ajouter un trajet simple au catalogue
//
// Associe respectivement vilDep,vilArr et moyenT aux attributs villeDepart, villeArrivee et moyenTransport de TrajetSimple
//

virtual ~TrajetSimple ();
// Appelé à la fin du programme, à la destruction du catalogue
//
// détruit les attributs villeDepart, villeArrivee et moyenTransport
//

//------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  char * villeDepart;
  char * villeArrivee;
  char * moyenTransport;
};

#endif // TrajetSimple_H
