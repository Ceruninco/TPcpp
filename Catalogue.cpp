/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 18/11/19
    *************************************************************************/
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetComp.h"
#include "Catalogue.h"
#include "File.h"


//#define MAP

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::load_saved(){

  ifstream fichier("BDtrajet.txt");
      vector<string> result;

      string buffer;
      fichier >> buffer;
      stringstream ss(buffer);


    char delim = '%';
    string token;

    while (std::getline(ss, token, delim)) {
        result.push_back(token);

    }

    vector<string>* result2 = new vector<string>[result.size()];
  for (unsigned int i = 0; i < result.size(); i++)
  {

    stringstream ges(result[i]);
    char delim = ';';
    string token;

    while (std::getline(ges, token, delim)) {
        result2[i].push_back(token);
    }
  }
    for(unsigned int i =0; i< result.size(); i++){
      cout << "trajet numero " << i << endl;
      if(result2[i][1]=="A"){
        TrajetSimple* t=new TrajetSimple(const_cast<char *>(result2[i][3].c_str()),const_cast<char *>(result2[i][4].c_str()), const_cast<char *>(result2[i][5].c_str()));

        insererTrajet(*t);
      }else if(result2[i][1]=="B"){
        TrajetComp* *listeTrajetsComp=new TrajetComp*[atoi(const_cast<char *>(result2[i][2].c_str()))];
        TrajetComp* t;
        t=new TrajetComp(const_cast<char *>(result2[i][3].c_str()), const_cast<char *>(result2[i][4].c_str()), const_cast<char *>(result2[i][5].c_str()), nullptr);
        listeTrajetsComp[0]=t;

  for(int c=1;c<atoi(result2[i][2].c_str());c++)
  {
    t=new TrajetComp(const_cast<char *>(result2[i][3+3*c].c_str()), const_cast<char *>(result2[i][4+3*c].c_str()), const_cast<char *>(result2[i][5+3*c].c_str()), nullptr);
    listeTrajetsComp[c]=t;
  }

  for(int c=0;c<atoi(const_cast<char *>(result2[i][2].c_str()))-1;c++)
  {
    listeTrajetsComp[c]->setSuivant(listeTrajetsComp[c+1]);
  }
  listeTrajetsComp[atoi(const_cast<char *>(result2[i][2].c_str()))-1]->setSuivant(nullptr);

  insererTrajet(*listeTrajetsComp[0]);
  delete[] listeTrajetsComp;
      }
      for(unsigned int j= 0; j<result2[i].size();j++){
        cout << result2[i][j] << "+";
      }
      cout << '\n' << endl;
    }

}

void Catalogue::insererTrajet(TrajetSimple& trajet){
  #ifdef MAP
      cout << "Appel a la méthode <insererTrajet> de <Catalogue>" << endl;
  #endif
    ajoutListe(trajet);
}

void Catalogue::ajoutListe(TrajetSimple& leTrajet) {
  #ifdef MAP
      cout << "Appel a la méthode <ajoutListe> de <Catalogue>" << endl;
  #endif
  entreeCatalogue* nouveauTrajet = new entreeCatalogue;
  nouveauTrajet->trajet = &leTrajet;
  nouveauTrajet->suivant=nullptr;
  if (debutCatalogue == nullptr) {
    debutCatalogue = nouveauTrajet;
	}
	else {
		finCatalogue->suivant = nouveauTrajet;
	}
  finCatalogue = nouveauTrajet;
	tailleCatalogue++;
}

void Catalogue::enregistrer()
{
    #ifdef MAP
      cout << "Appel a la méthode <enregistrer> de <Catalogue>" << endl;
  #endif
    cout<<endl;
    int i=1;
    entreeCatalogue* lecture=debutCatalogue;
    ofstream fichier("BDtrajet.txt",ios::out|ios::trunc);

    string entete= {"%"};
    while(lecture!=NULL)
    {

      string nb= to_string(i);
      string aStocker = {lecture->trajet->description_save()};
      string aEnvoyer = {nb+';'+aStocker+entete};
      fichier << aEnvoyer;
      lecture=lecture->suivant;
      i++;
    }
  fichier.close();
}

void Catalogue::afficherTrajets()const
{
  #ifdef MAP
      cout << "Appel a la méthode <afficherTrajets> de <Catalogue>" << endl;
  #endif
    cout<<endl;
    int i=1;
    entreeCatalogue* lecture=debutCatalogue;
    while(lecture!=NULL)
    {
      cout << i << ". ";
      lecture->trajet->afficher();
      cout << endl;
      lecture=lecture->suivant;
      i++;
    }
    cout<<endl;
}

int Catalogue::rechercherTrajet(char* villeD, char* villeA)const
{
  #ifdef MAP
      cout << "Appel a la méthode <rechercherTrajet> de <Catalogue>" << endl;
  #endif
  int i = 1;
  entreeCatalogue* lecture=debutCatalogue;
  while(lecture!=nullptr)
  {
    if(lecture->trajet->trajetCorrespond(villeD,villeA)==1){
      cout << i << ". ";
      lecture->trajet->afficher();
      cout << endl;
      i++;
    }
    lecture=lecture->suivant;
  }
  cout << endl;

  if(i==1){
    cout << "aucun trajet trouvé" << endl;
    cout<<endl;
    return -1;
  }else{
    return 1;
  }
}

void Catalogue::insertionSimple()
{
  #ifdef MAP
      cout << "Appel a la méthode <insertionSimple> de <Catalogue>" << endl;
  #endif

  char* villeD;
  char* villeA;
  char* transport;
  char* buffer=new char[1000];

  cout<<"ville de départ ?"<<endl;
  cin>>buffer;
  villeD=new char[strlen(buffer)+1];
  strcpy(villeD,buffer);
  cout<<"ville d'arrivée ?"<<endl;
  cin>>buffer;
  villeA=new char[strlen(buffer)+1];
  strcpy(villeA,buffer);
  cout<<"transport ?"<<endl;
  cin>>buffer;
  transport=new char[strlen(buffer)+1];
  strcpy(transport,buffer);
  TrajetSimple* t=new TrajetSimple(villeD,villeA, transport);

  insererTrajet(*t);
  delete [] villeD;
  delete [] villeA;
  delete [] transport;
  delete [] buffer;
}

void Catalogue::insertionCompose()
{
  #ifdef MAP
      cout << "Appel a la méthode <insertionCompose> de <Catalogue>" << endl;
  #endif
  char* villeD;
  char* villeA;
  char* villeAbis;
  char* transport;
  char* buffer=new char[1000];

  int nbTrajets;
  cout<<"nombre de trajets composant le trajet ?"<<endl;
  cin>>nbTrajets;

  TrajetComp* *listeTrajetsComp=new TrajetComp*[nbTrajets];
  TrajetComp* t;

  cout<<"ville de départ ?"<<endl;
  cin>>buffer;
  villeD=new char[strlen(buffer)+1];
  strcpy(villeD,buffer);
  cout<<"ville d'arrivée ?"<<endl;
  cin>>buffer;
  villeA=new char[strlen(buffer)+1];
  strcpy(villeA,buffer);
  cout<<"transport ?"<<endl;
  cin>>buffer;
  transport=new char[strlen(buffer)+1];
  strcpy(transport,buffer);

  t=new TrajetComp(villeD, villeA, transport, nullptr);
  listeTrajetsComp[0]=t;

  delete [] villeD;
  delete [] transport;

  for(int i=1;i<nbTrajets;i++)
  {
    cout<<"ville étape n°"<<i<<" :"<<endl;
    cout << villeA << endl;

    cout<<"ville d'arrivée ?"<<endl;
    cin>>buffer;
    villeAbis=new char[strlen(buffer)+1];
    strcpy(villeAbis,buffer);
    cout<<"transport ?"<<endl;
    cin>>buffer;
    transport=new char[strlen(buffer)+1];
    strcpy(transport,buffer);

    t=new TrajetComp(villeA, villeAbis, transport, nullptr);
    listeTrajetsComp[i]=t;
    delete [] villeA;
    villeA=new char[strlen(villeAbis)+1];
    strcpy(villeA,villeAbis);

    delete [] villeAbis;
    delete [] transport;
  }
  delete [] villeA;
  for(int i=0;i<nbTrajets-1;i++)
  {
    listeTrajetsComp[i]->setSuivant(listeTrajetsComp[i+1]);
  }
  listeTrajetsComp[nbTrajets-1]->setSuivant(nullptr);

  insererTrajet(*listeTrajetsComp[0]);

  delete [] buffer;
  delete [] listeTrajetsComp;
}

char** Catalogue::creerGraphe(int* tailleGraphe)const
{
  #ifdef MAP
      cout << "Appel a la méthode <creerGraphe> de <Catalogue>" << endl;
  #endif
  entreeCatalogue* lecture=debutCatalogue;
  char** tableau = new char*[100];
      for (int i = 0; i < 100; i++){
                 tableau[i] = new char[100];
      }
  int nbrempli=0;
  while(lecture!=nullptr)
  {
    if(estPresent(lecture->trajet->getVilleDepart(),tableau, nbrempli)==0){
      strcpy(tableau[nbrempli],lecture->trajet->getVilleDepart());
      nbrempli++;
    }
    if(estPresent(lecture->trajet->villeFin(),tableau, nbrempli)==0){
      strcpy(tableau[nbrempli], lecture->trajet->villeFin());
      nbrempli++;
    }
    lecture=lecture->suivant;
  }
  *tailleGraphe=nbrempli;
  return tableau;
}

int Catalogue::estPresent(char* element, char** tableau, int taille)const
{
  #ifdef MAP
      cout << "Appel a la méthode <estPresent> de <Catalogue>" << endl;
  #endif
    for(int i=0;i<taille;i++){
      if(strcmp(tableau[i],element)==0){
        return 1;
      }
    }
    return 0;
}

int Catalogue::Dijsktra(char* depart, char* arrivee)const
{
  #ifdef MAP
  cout << "Appel a la méthode <Dijsktra> de <Catalogue>" << endl;
  #endif
  cout<<endl;
  int trouve = 0;
  char** grapheVilles;
  int* tailleGraphe = new int;
  *tailleGraphe=0;
  grapheVilles=creerGraphe(tailleGraphe);
  int** tabDistance = new int*[*tailleGraphe];
  for (int i = 0; i < (*tailleGraphe); i++){
    tabDistance[i] = new int[100];
  }
  for(int i=0; i<(*tailleGraphe);i++){
    for(int j=0; j<(*tailleGraphe);j++){
      if(i!=j){
        tabDistance[i][j]=INT8_MAX;
      }else{
        tabDistance[i][j]=0;
      }
    }
  }
  entreeCatalogue* lecture=debutCatalogue;
  while(lecture!=NULL)
  {
    int villeDep=-1;
    int villeArr=-1;
    for(int i = 0; i<(*tailleGraphe); i++){
      if(strcmp(lecture->trajet->getVilleDepart(),grapheVilles[i])==0){
        villeDep=i;
      }
      if(strcmp(lecture->trajet->villeFin(),grapheVilles[i])==0){
        villeArr=i;
      }
    }
    tabDistance[villeDep][villeArr]=1;
    lecture=lecture->suivant;
  }
  int villeDep=-1;
  for(int i =0; i<(*tailleGraphe);i++){
    if(strcmp(depart,grapheVilles[i])==0){
      villeDep=i;
    }
  }
  if(villeDep==-1){
    cout << "Aucun trajet trouvé" << endl;
    cout<<endl;

    for (int i = 0; i < (*tailleGraphe); i++){
      delete[] tabDistance[i];
    }
    for(int i=0; i<100; i++){
      delete[] grapheVilles[i];
    }
    delete[] grapheVilles;
    delete[] tabDistance;
    delete tailleGraphe;
    return 0;
  }
  File* debutQueue = new File;
  int* predecesseurs = new int[(*tailleGraphe)];
  for(int i=0; i<(*tailleGraphe);i++){
    if(tabDistance[villeDep][i]==1){
		debutQueue->queue(i);
      predecesseurs[i]=villeDep;
    }
  }
  int val = 0;
  while(debutQueue->dequeue(&val)!=0){
    if(strcmp(grapheVilles[val],arrivee)==0){
      trouve =1;
      int actuel = val;
      int nbtrajet = 0;
      while(actuel!=villeDep){
        nbtrajet++;
        actuel = predecesseurs[actuel];
      }
      int* chemin = new int[nbtrajet+1];
      actuel = val;

      for(int i=0; i<nbtrajet+1;i++){
        chemin[nbtrajet-i]=actuel;
        actuel = predecesseurs[actuel];
      }

      for(int i=0; i<nbtrajet;i++){
        cout << "Choisissez parmi ces trajets pour l'" << "étape " << i+1 << " : " << endl;
        rechercherTrajet(grapheVilles[chemin[i]],grapheVilles[chemin[i+1]]);
      }
      cout << endl;
      delete[] chemin;
    }else{
      for(int i=0; i<(*tailleGraphe);i++){
        if(tabDistance[val][i]==1){
			debutQueue->queue(i);
          predecesseurs[i]=val;
        }
      }
    }

  }
  if(trouve==0){
    cout << "aucun trajet trouvé " << endl;
    cout<<endl;
  }

  delete[] predecesseurs;
  for (int i = 0; i < (*tailleGraphe); i++){
    delete[] tabDistance[i];
  }
  for(int i=0; i<100; i++){
    delete[] grapheVilles[i];
  }
  delete[] grapheVilles;
  delete debutQueue;
  delete[] tabDistance;
  delete tailleGraphe;
  if (trouve==0) {
	  return 0;
  }
  else {
	  return 1;
  }

}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
  tailleCatalogue = unCatalogue.tailleCatalogue;
} //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
  debutCatalogue = nullptr;
  finCatalogue = nullptr;
  tailleCatalogue = 0;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
  entreeCatalogue* ptr;
  while(debutCatalogue!=nullptr)
  {
    delete debutCatalogue->trajet;
    ptr=debutCatalogue->suivant;
    delete debutCatalogue;
    debutCatalogue=ptr;
  }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
