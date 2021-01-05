/*************************************************************************
                           LinkedList  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LinkedList> (fichier LinkedList.h) ----------------
#if ! defined ( LINKEDLIST_H )
#define LINKEDLIST_H
//--------------------------------------------------- Interfaces utilisées

#include "Data.h"
#include "Trajet.h"
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LINKEDLIST>
// Liste chainee utilise pour stocker les trajets de facon ordonee
// Elle comporte des methodes utiles pour la recherche de trajets
//
//------------------------------------------------------------------------

class LinkedList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
// type Méthode ( liste des paramètres );

	void Ajouter (const Trajet * unTrajet);
	//Ajoute unTrajet, pointeur sur un objet de type Trajet dans la liste

    void Ecrire(std::ofstream & of) const;
    // Ecrit dans un fichier les trajets présents dans la liste

    void Save (std::ofstream & os, const char * typetrajet, const char * vd, const char * va) const;
	// Ecrit dans un fichier les trajets de la liste qui correspondent aux
	// données entrées en paramètres 
	
	void Afficher(const char * mess = "") const;
	//Afficher les trajets presents dans la liste

	bool operator == (const LinkedList & ll) const;
	//Renvoie true si this et ll sont de meme longeur et 
	// comportent exactement les memes trajets
	//(Se referer a operateur== dans les classes TrajetSimple et TrajetCompose)

	bool Contains(const Trajet * unTrajet)const;
	//Renvoie true s'il existe un trajet identique au
	//Trajet pointe par unTrajet dans cette liste
	//(Se referer a operateur== dans les classes TrajetSimple et TrajetCompose)



//-------------------------------------------- Constructeurs - destructeur
	LinkedList();
	//Constructeur de la classe LinkedList

	LinkedList(const LinkedList & ll);
	//Constructeur de copie de la classe LinkedList
	//Recopie tout les trajets presents dans ll et les 
	//Insere dans this

	~LinkedList();
	//Destructeur de la classe LinkedList
	//Detruit aussi les cellules Data presentes dans la liste

	//Classes amies
	friend class Catalogue;
//------------------------------------------------------------------ PRIVE
	
protected:
//----------------------------------------------------- Méthodes protégées
	Data * head;
	//Pointeur sur la premiere cellule de donnees de la liste

	Data * tail;
	//Pointeur sur la derniere cellule de donnees de la liste
	
//----------------------------------------------------- Attributs protégés	
};

//-------------------------------- Autres définitions dépendantes de <LinkedList>

#endif // LINKEDLIST_H

