
/*************************************************************************
                           TrajetComp  -  description
Un TrajetComp possède les memes attributs qu'un TrajetSimple, mais possède en plus un pointeur vers le trajet suivant (un TrajetComp) qui constitue le trajet composé
On peut afficher les informations des TrajetComp qui constituent un trajet composé et rechercher des correspondances avec des villes des TrajetComp

                             -------------------
    début                : 18/11/19
    *************************************************************************/

//---------- Interface de la classe <TrajetComp> (fichier TrajetComp.h) ----------------
#if ! defined ( TrajetComp_H )
#define TrajetComp_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetComp>
// Classe modélisant un trajet composé :
// possède une ville de départ et une ville d'arrivée, un moyen de transport et un pointeur vers un autre trajet composé
//
//------------------------------------------------------------------------

class TrajetComp : public TrajetSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
virtual string description_save();

void afficher()const;
// Appelée par la méthode afficherTrajets de catalogue suite au menu avec l'entrée 3
//
// Affiche le contenu du trajet composé : parcourt l'ensemble des trajetComp constituant un trajet composé et affiche ville de départ, ville d'arrivée, moyen de transport de chaque trajetComp
//

int trajetCorrespond(char* villeDepart, char * villeArrivee)const;
// Appelée par la méthode rechercherTrajet de catalogue suite au menu avec l'entrée 4
//
// Compare les informations du trajet recherché avec celles du trajet composé (ville de départ du premier trajetComp et ville d'arrivée du dernier trajetComp), renvoie 1 si celles ci correspondent
//

virtual char* villeFin() const;
// Renvoie la ville d'arrivée du dernier TrajetComp
//


virtual int tailleTrajet() const;
// Renvoie la taille du trajet composé, c'est à dire le nombre de TrajetComp constituant le trajet composé
//


void setSuivant(TrajetComp* next);
// Associe next à l'attribut suivant de TrajetComp
//

//-------------------------------------------- Constructeurs - destructeur
    TrajetComp (const TrajetComp & unTrajetComp);
    // copie les informations de unTrajetComp
    //

    TrajetComp (char * vilDep, char *  vilArr, char *  moyenT , TrajetComp* suivant);
    // Appelé au menu par l'entrée 2 pour ajouter un trajet composé au catalogue
    //
    // Associe respectivement vilDep, vilArr, moyenT et suivant aux attributs villeDepart, villeArrivee, moyenTransport et suivant d'un TrajetComp constituant un trajet composé
    //suivant pointe vers le prochain trajet (un TrajetComp) qui constitue le trajet composé
    //Le dernier trajetComp constituant le trajet composé a pour suivant le pointeur nullptr

    virtual ~TrajetComp ();
    // Appelé à la fin du programme, à la destruction du catalogue
    //
    // détruit les attributs villeDepart, villeArrivee, moyenTransport et suivant

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	TrajetComp * suivant;
};


#endif // TrajetComp_H
