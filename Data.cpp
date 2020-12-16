/*************************************************************************
                           Data  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Data> (fichier Data.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Data.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC		
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Data::Data(const Trajet * unTrajet)
{	
	#ifdef MAP
		cout << "Appel au constructeur de <Data>" << endl;
	#endif
	current = unTrajet;
	next = NULL;
} //----- Fin de Data

Data::~Data()
{
	delete current;
} //-----Fin de ~Data
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
