
/*************************************************************************
                           TrajetSimple  -  description
un TrajetSimplemodélise un trajet simple constitué d'une ville de départ, d'une ville d'arrivée et d'un moyen de transport
On peut afficher ces informations et rechercher des correspondances avec des villes
                             -------------------
    début                : 18/11/19
    *************************************************************************/
//---------- Réalisation de la classe <File> (fichier File.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//#define MAP

//------------------------------------------------------ Include personnel
#include "File.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void File::queue (int val){
  #ifdef MAP
    cout << "Appel a la méthode <queue> de <File>" << endl;
  #endif
  Queue* bout = new Queue;
  bout->value = val;
  bout->suivant=nullptr;
  if (file == nullptr) {
    file = bout;
	}
	else {
		finFile->suivant = bout;
	}
  finFile = bout;
	taillequeue++;
}//----- Fin de Méthode


int File::dequeue(int* val){
  #ifdef MAP
    cout << "Appel a la méthode <dequeue> de <File>" << endl;
  #endif
  int value;
	if (taillequeue == 1) {
		value = file->value;
		delete file;
		finFile = nullptr;
    file=nullptr;
	}
	else if(taillequeue == 0){
		return 0;
	}
	else {
    value = file->value;
    Queue* ptr;
    ptr = file;
		file = file->suivant;
    delete ptr;
	}
	taillequeue--;
	*val = value;
	return 1;
}//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
File::File()
{
  #ifdef MAP
      cout << "Appel au constructeur de <File>" << endl;
  #endif
  file = (Queue*)nullptr;
  finFile = (Queue*)nullptr;
  taillequeue = 0;
}//----- Fin de File

File::~File()
  {
    #ifdef MAP
        cout << "Appel au destructeur de <File>" << endl;
    #endif
    
  } //----- Fin de File
