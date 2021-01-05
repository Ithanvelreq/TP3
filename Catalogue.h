/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H
//--------------------------------------------------- Interfaces utilisées
#include "LinkedList.h"
#include "Trajet.h"
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CATALOGUE>
//Classe qui gere la colection de trajets simples et composes
//Elle permets de afficher tous les trajets ainsi que de faire
//La recherche d'un trajet particulier
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
		
// type Méthode ( liste des paramètres );
	void Ajouter(const Trajet * unTrajet);
	//Ajoute unTrajet au catalogue

	void Recherches(const char * vd, const char * va) const;
	//Recherche simple d'un trajet qui va de la ville vd a la ville va
	//Sans escale et l'affiche

	void Recherchea(const char * vd, const char * va) const;
	//Recherche avancee de tous les trajets qui vont de la ville va a 
	//la ville vd et les afficher

	void Afficher() const;
	//Affichage de la colection de trajets
	
	void Save(std::ofstream & os, const char * typetrajet, const char * vd, const char * va) const;
	//Ecriture dans un fichier tous les trajets qui verifient les contraintes dans typetrajet vd va

//-------------------------------------------- Constructeurs - destructeur
	Catalogue();
	//Constructeur de la classe Catalogue

	~Catalogue();
	//Destructeur de la classe Catalogue

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	void rechercheRecurrente(LinkedList * pp, const char * va) const;
	//Recherche recurrente utilisee lors de la recherche avancee
	//Algorithme:
	//Algorithme de type glouton, cherche tous les chemins possibles
	//Pour arriver a la ville va de facon recurrente puis elimine
	//ceux qui sont sans issue

	void creerCopie(LinkedList * pp, const Trajet * t) const;
	//Methode qui cree une copie du Trajet pointe par t
	//et l'ajoute a la LinkedList pp

//----------------------------------------------------- Attributs protégés

	LinkedList * listeTrajets;
	//Liste chainee utilise pour stocker les trajets
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

