
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
  int sousrequete;
  do
  {
    cout<<"1 pour ajouter un trajet simple"<<endl;
    cout<<"2 pour ajouter un trajet composé"<<endl;
    cout<<"3 pour afficher les trajets"<<endl;
    cout<<"4 pour rechercher un trajet"<<endl;
    cout<<"5 pour faire une recherche avancée d'un trajet"<<endl;
      cout<<"6 pour sauvegarder"<<endl;
      cout<<"7 pour load la DB"<<endl;
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
      case 6 :
      {
        monCatalogue.enregistrer();
      }
      break;
      case 7 :
        {
          cout<<"        1 pour charger tout"<<endl;
          cout<<"        2 pour charger uniquement les trajet simples"<<endl;
          cout<<"        3 pour charger uniquement les trajet composés"<<endl;
          cout<<"        4 pour charger les trajets en fonction de villes particulières"<<endl;
          cout<<"        5 pour charger un intervalle de trajets "<<endl;
          scanf("%d", &sousrequete);
          switch(sousrequete)
          {
            case 1:
            {
              monCatalogue.load_savedAll();
            }
            break;
            case 2:
            {
              monCatalogue.load_savedSimple();
            }
            break;
            case 3:
            {
              monCatalogue.load_savedComp();
            }
            break;
            case 4:
            {
              monCatalogue.load_savedDepArr();
            }
            break;
            case 5:
            {
              monCatalogue.load_savedSelec();
            }
            break;

          }

        }
        break;
    }
  }while(requete!=0);
  return 0;
}
