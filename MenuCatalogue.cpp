
//coucou mec
#include <iostream>
#include <cstring>
#include "TrajetComp.h"
#include "TrajetSimple.h"
#include "Catalogue.h"
using namespace std;

Catalogue monCatalogue;

int main(void)
{
  int requete;
  do
  {
    cout<<"1 pour ajouter un trajet simple"<<endl;
    cout<<"2 pour ajouter un trajet composé"<<endl;
    cout<<"3 pour afficher les trajets"<<endl;
    cout<<"4 pour rechercher un trajet"<<endl;
    cout<<"5 pour faire une recherche avancée d'un trajet"<<endl;
    cout<<"0 pour quitter"<<endl;
    scanf("%d", &requete);

    switch(requete)
    {
      case 1:
      monCatalogue.insertionSimple();
      break;
    case 2 :
      monCatalogue.insertionCompose();
      break;
    case 3 :
      monCatalogue.afficherTrajets();
      break;
    case 4 :
      {
        char* buffer=new char[1000];
        char* villeD;
        char* villeA;
        cout<<"ville de départ ?"<<endl;
        cin >> buffer;
        villeD=new char[strlen(buffer)+1];
        strcpy(villeD,buffer);
        cout<<"ville d'arrivée ?"<<endl;
        cin >> buffer;
        villeA=new char[strlen(buffer)+1];
        strcpy(villeA,buffer);
        delete [] buffer;
        monCatalogue.rechercherTrajet(villeD, villeA);
        delete [] villeD;
        delete [] villeA;
      }
      break;
    case 5 :
      {
        char* buffer=new char[1000];
        char* villeD;
        char* villeA;
        cout<<"ville de départ ?"<<endl;
        cin >> buffer;
        villeD=new char[strlen(buffer)+1];
        strcpy(villeD,buffer);
        cout<<"ville d'arrivée ?"<<endl;
        cin >> buffer;
        villeA=new char[strlen(buffer)+1];
        strcpy(villeA,buffer);
        delete [] buffer;
        monCatalogue.Dijsktra(villeD,villeA);
        delete [] villeD;
        delete [] villeA;
      }
      break;
    }
  }while(requete!=0);
  return 0;
}
