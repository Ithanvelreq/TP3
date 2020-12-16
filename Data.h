/*************************************************************************
                           Data  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LinkedList> (fichier Data.h) ----------------
#if ! defined ( DATA_H )
#define DATA_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DATA>
//Classe utilise comme maillon de notre LinkedList
//Elle sert a stocker les differents objets de type
//Trajet dans notre LinkedList
//------------------------------------------------------------------------

class Data
{
//----------------------------------------------------------------- PUBLIC
public:
	const Trajet * current;
    //Pointeur sur le trajet contenu dans cette structure
	Data * next;
    //Pointeur sur la prochaine cellule de la liste ordonee LinkedList

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
	Data(const Trajet * unTrajet);
	// Construis un cellule de donnees utilisee pour notre LinkedList
    // et insere le pointeur sur Trajet unTrajet

	~Data();
	// Detruit une cellule de donnes pour notre LinkedList
    // Et aussi le Trajet associe
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés	
};

//-------------------------------- Autres définitions dépendantes de <Data>

#endif // DATA_H

