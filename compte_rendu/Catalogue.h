/*************************************************************************
                           Catalogue  -  description
Le catalogue liste l'ensemble des trajets insérés par l'utilisateur.
Il y a 2 méthodes d'insertion (insertionSimple et insertionCompose), une seule est utilisée en fonction du type de trajet que l'utilisateur veut ajouter au niveau de l'interface utilisateur :
soit simple soit composé.
Elles permettent à l'utilisateur de rentrer les informations des trajets qui sont ensuite ajoutés à la liste du catalogue grace la méthode ajoutListe, par l'intermediaire de insererTrajet
Il est ensuite possible de visualiser les trajets ajoutés avec la méthode afficherTrajets
L'utilisateur peut aussi rechercher les différents trajets possible d'une ville à une autre.
Il peut choisir de rechercher les trajets possible n'utilisant qu'un seul trajet (simple/composé) ou les trajets combinants ceux-ci.
Le résultat de la recherche (les enchaînements de trajet possibles)
sera alors affiché sur l'interface utilisateur
                             -------------------
    début                : 18/11/19
    *************************************************************************/

#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetSimple.h"
#include <string>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// La classe repertorie l'ensemble des trajets simples et composés qui ont été ajoutés
//
//------------------------------------------------------------------------

class Catalogue
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void insererTrajet(TrajetSimple& trajet);
	//  Appelée à chaque ajout de trajet ( cf insertionSimple et insertionCompose)
	//
	// cf queue

	void afficherTrajets()const;
	//  Appelée au menu par l'entrée 3
	//
	// parcourt la liste des trajets et appelle la méthode afficher de chacun d'eux pour afficher les informations de chaque trajet

	int rechercherTrajet(char* villeD, char* villeA)const;
	// Appelée au menu par l'entrée 4, l'utilisateur rentre la ville de départ et d'arrivée du trajet recherché
	//
	// parcourt la liste des trajets dans le catalogue et appelle la méthode trajetCorrespond du trajet en question
	//					 affiche les informations du trajet si les villes recherchées correspondent (appelle de la méthode afficher)
	//					 message si aucun trajet correspondant n'a été trouvé
	//
	void insertionSimple();
	// Appelée au menu par l'entrée 1, l'utilisateur doit rentrer le nom de la ville de départ, de la ville d'arrivée et du moyen de transport du trajet
	//
	// un nouveau trajet est créé puis ajouté à la liste du catalogue en appelant la méthode insérerTrajet

	void insertionCompose();
	// Appelée au menu par l'entrée 2, l'utilisateur doit d'abord rentrer le nombre de trajet constituant le trajet composé,
	// puis rentrer le nom de la ville de départ, de la ville d'arrivée et du moyen de transport du trajet 1er trajet.
	//L'utilisateur rentre ensuite les villes étapes du trajet composé et les moyens de transport correspondant pour arriver à la ville finale
	//
	// un nouveau trajet est créé puis ajouté à un tableau pour chaque étape du trajet composé,
	//chaque trajet pointe sur sa case suivante du tableau pour désigner son suivant, le dernier trajet a pour suivant nullptr
	//le trajet composé n°1 (1er trajet du trajet compsoé) est ajouté à la liste du catalogue avec la méthode insérerTrajet

	char** creerGraphe(int* tailleGraphe)const;
	// Renvoie un tableau char** contenant toutes les villes étant soit au début soit à la fin d'un trajet simple ou composé
	// Méthode utilisée pour ensuite remplir la matrice des trajets possibles entre ces villes


	int estPresent(char* element, char** tableau, int taille)const;
	// renvoie 1 si la chaîne de caractère "element" est présente dans le tableau de chaînes de caractères "tableau" de taille "taille"
	// renvoie 0 sinon

	void enregistrer();
	// Ecrit dans un fichier texte la version modifiée pour le stockage du catalogue 


	int Dijsktra(char* depart, char* arrivee)const;
	// version avancée de la recherche de trajet
	// Appelée au menu par l'entrée 5, l'utilisateur rentre la ville de départ et d'arrivée du trajet recherché
	// permet de rechercher les différents trajets possibles entre la ville de départ "depart" et la ville d'arrivée "arrivee"
	//	renvoie 1 si au moins un trajet est possible
	//	renvoie 0 sinon


	//-------------------------------------------- Constructeurs - destructeur
	Catalogue (const Catalogue & unCatalogue);
	// constructeur de copie de catalogue

	Catalogue ();
	// Constructeur de catalogue,Appelé au début du programme
	//
	// initialise les attributs tailleCatalogue, debutCatalogue et finCatalogue

	virtual ~Catalogue ();
	// Appelé à la fin du programme
	//
	// parcourt la liste des trajets et appelle le destructeur de chacun, détruis chaque morceau de la liste

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées
	void ajoutListe(TrajetSimple& trajet);
	// Appelé lorsque l'on ajoute un nouveau trajet simple ou composé
	//
	// ajoute le nouveau trajet à la fin de la liste chaînée de TrajetSimple du catalogue, augmente la taille de la liste
	//

	//----------------------------------------------------- Attributs protégés

	typedef struct _entreeCatalogue {
		TrajetSimple* trajet;
		_entreeCatalogue* suivant;
	}	entreeCatalogue;

	entreeCatalogue * debutCatalogue;
	entreeCatalogue * finCatalogue;
	int tailleCatalogue;
};

#endif // Catalogue_H
