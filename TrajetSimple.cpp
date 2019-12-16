/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 18/11/19
    *************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
//#define MAP

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string TrajetSimple::description_save(){
 string description;
    description="A;1;"+TrajetSimple::afficher_save();
    return description;
}
string TrajetSimple::afficher_save(){
  string description;
     description=string(villeDepart)+";"+string(villeArrivee)+";"+string(moyenTransport)+";";
     return description;
}
void TrajetSimple::afficher()const
{
  #ifdef MAP
    cout << "Appel a la méthode <afficher> de <TrajetSimple>" << endl;
  #endif
    cout<< "de " << villeDepart <<" à "<< villeArrivee << " en "<< moyenTransport;
} //----- Fin de Méthode

int TrajetSimple::trajetCorrespond(char* villeDepart, char * villeArrivee)const
{
  #ifdef MAP
    cout << "Appel a la méthode <trajetCorrespond> de <TrajetSimple>" << endl;
  #endif
  if(strcmp(this->villeDepart,villeDepart)==0&&strcmp(this->villeArrivee,villeArrivee)==0){
    return 1;
  }
  else
  {
    return 0;
  }
} //----- Fin de Méthode

char* TrajetSimple::villeFin() const
{
  #ifdef MAP
    cout << "Appel a la méthode <villeFin> de <TrajetSimple>" << endl;
  #endif
  return villeArrivee;
}//----- Fin de Méthode

int TrajetSimple::tailleTrajet() const
{
  #ifdef MAP
    cout << "Appel a la méthode <tailleTrajet> de <TrajetSimple>" << endl;
  #endif
  return 1;
}//----- Fin de Méthode

char* TrajetSimple::getVilleDepart() const
{
	#ifdef MAP
    cout << "Appel a la méthode <getVilleDepart> de <TrajetSimple>" << endl;
  #endif
	return villeDepart;
}

char* TrajetSimple::getMoyenTransport() const
{
	#ifdef MAP
    cout << "Appel a la méthode <getMoyenTransport> de <TrajetSimple>" << endl;
  #endif
	return moyenTransport;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
	villeDepart = new char[strlen(unTrajetSimple.villeDepart)+1];
	strcpy(villeDepart, unTrajetSimple.villeDepart);
	villeArrivee = new char[strlen(unTrajetSimple.villeArrivee)+1];
	strcpy(villeArrivee, unTrajetSimple.villeArrivee);
	moyenTransport = new char[strlen(unTrajetSimple.moyenTransport)+1];
	strcpy(moyenTransport, unTrajetSimple.moyenTransport);

} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple (char *  vilDep, char *  vilArr, char *  moyenT )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	villeDepart = new char[strlen(vilDep)+1];
	strcpy(villeDepart, vilDep);
	villeArrivee = new char[strlen(vilArr)+1];
	strcpy(villeArrivee, vilArr);
	moyenTransport = new char[strlen(moyenT)+1];
	strcpy(moyenTransport, moyenT);
}//----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

	delete []villeDepart;
	delete []villeArrivee;
	delete []moyenTransport;

} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
