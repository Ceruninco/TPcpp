
/*************************************************************************
                           File  FIFO (first in - first out) d'entiers
					L'élèment ajouté à la file en premier sera traité en premier

                             -------------------
    début                : 18/11/19
    *************************************************************************/
#if ! defined ( File_H )
#define File_H
//------------------------------------------------------------------------
// Rôle de la classe <File>
// File FIFO utilisée pour afficher les trajets possibles une fois l'algorithme de recherche terminé
//
//------------------------------------------------------------------------

class File
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
void queue(int valeur);
// Ajoute "valeur" à la file


int dequeue(int* val);
// Renvoie la première valeur de la file insérée et non renvoyée : la valeur la plus ancienne de la file
//	Supprime cette valeur de la file


//-------------------------------------------- Constructeurs - destructeur
File();
// Constructeur de file


~File();
// Destructeur de file


//------------------------------------------------------------------ PRIVE

protected:

  //----------------------------------------------------- Attributs protégés
// structure Queue : bloc élémentaire de la file
  typedef struct _Queue {
    int value;
    _Queue* suivant;
  }Queue;
  // pointeur sur le premier bloc
  Queue* file;
  //pointeur sur le dernierbloc
  Queue* finFile;
  int taillequeue;
};

#endif // File_H
