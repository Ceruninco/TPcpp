/*************************************************************************
                           TrajetComp  -  description
                             -------------------
    début                : 18/11/19
    *************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetComp.h"
//#define MAP

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string TrajetComp::description_save(){
 string description;

    stringstream s;
    s << tailleTrajet();
    string s1;
    s >> s1;
    description="B;"+s1+";"+string(villeDepart)+";"+string(villeArrivee)+";"+string(moyenTransport)+";";

    TrajetComp * lecture = suivant;
    while(lecture!=nullptr)
    {
      description+= string(villeDepart)+";"+string(villeArrivee)+";"+string(moyenTransport)+";";
      lecture=lecture->suivant;
    }
    return description;

}
 void TrajetComp::afficher()const
{
  #ifdef MAP
      cout << "Appel a la méthode <afficher> de <TrajetComp>" << endl;
  #endif
      TrajetSimple::afficher();
      TrajetComp * lecture = suivant;
      while(lecture!=nullptr)
      {
        cout << " - ";
        lecture->TrajetSimple::afficher();
        lecture=lecture->suivant;
      }
} //----- Fin de Méthode

int TrajetComp::trajetCorrespond(char* villeDepart, char * villeArrivee)const{
  #ifdef MAP
      cout << "Appel a la méthode <trajetCorrespond> de <TrajetComp>" << endl;
  #endif
  if(strcmp(this->villeDepart,villeDepart)==0){
    const TrajetComp* actuel = this;
    while(actuel->suivant!=nullptr){
    actuel=actuel->suivant;
    }
    if(strcmp(actuel->villeArrivee,villeArrivee)==0){
      return 1;
    }
  }
  return 0;
} //----- Fin de Méthode

char* TrajetComp::villeFin() const{
  #ifdef MAP
      cout << "Appel a la méthode <villeFin> de <TrajetComp>" << endl;
  #endif
  const TrajetComp* actuel = this;
  while(actuel->suivant!=nullptr){
  actuel=actuel->suivant;
  }
  return actuel->villeArrivee;
}//----- Fin de Méthode

int TrajetComp::tailleTrajet()const{
  #ifdef MAP
      cout << "Appel a la méthode <tailleTrajet> de <TrajetComp>" << endl;
  #endif
  const TrajetComp* actuel = this;
  int taille=1;
  while(actuel->suivant!=nullptr){
  actuel=actuel->suivant;
  taille++;
  }
  return taille;
}//----- Fin de Méthode

void TrajetComp::setSuivant(TrajetComp* next)
{
  #ifdef MAP
      cout << "Appel a la méthode <setSuivant> de <TrajetComp>" << endl;
  #endif
  suivant=next;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetComp::TrajetComp ( const TrajetComp & unTrajetComp )
: TrajetSimple(unTrajetComp)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetComp>" << endl;
#endif
  suivant = unTrajetComp.suivant;
} //----- Fin de TrajetComp (constructeur de copie)


TrajetComp::TrajetComp ( char * vilDep, char *  vilArr, char *  moyenT , TrajetComp* next)
: TrajetSimple(vilDep, vilArr, moyenT)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComp>" << endl;
#endif
  suivant = next;
} //----- Fin de TrajetComp


TrajetComp::~TrajetComp ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComp>" << endl;
#endif

  delete this->suivant;

} //----- Fin de ~TrajetComp


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
