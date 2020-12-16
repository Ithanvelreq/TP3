/*************************************************************************
                           ListOrd  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/
//---------- Interface de la classe <ListOrd> (fichier ListOrd.h) ------------->
#if ! defined ( LISTORD_H )
#define LISTORD_H
//--------------------------------------------------- Interfaces utilisées
#include "LinkedList.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LISTORD>
// Liste chainee dont la particularité est d'être ordonnée pour 
// qu'elle puisse être utilisée pour créer un trajet composé
// Elle hérite des attributs et des méthodes de la classe LinkedList
// La méthode Ajouter diffère et lui permet d'être ordonnée
//------------------------------------------------------------------------

class ListOrd : public LinkedList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// type Méthode ( liste des paramètres );

        void Ajouter (const Trajet * unTrajet);
        //Ajoute un pointeur de type Trajet * en vérifiant que l'objet 
        //pointé respecte l'ordre de la liste 

//-------------------------------------------- Constructeurs - destructeur
        ListOrd();
        //Constructeur de la classe ListOrd

        ListOrd(const ListOrd & ll);
        //Constructeur de copie de la classe ListOrd
        //Recopie tout les trajets presents dans ll et les 
	//Insere dans this

        ~ListOrd();
        //Destructeur de la classe ListOrd
	//Detruit aussi les cellules Data presentes dans la liste

        //Classes amies
        friend class TrajetCompose;
//------------------------------------------------------------------ PRIVE
        
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ListOrd>

#endif // LISTORD_H

