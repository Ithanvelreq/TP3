/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp>

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "ListOrd.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher (const char * mess /* = "TC"*/) const{
	listeTrajet->Afficher("TC");
}//Fin de Afficr

ListOrd * TrajetCompose::getterListeTrajet () const {
        return listeTrajet;
}//Fin de getterListeTrajet


//------------------------------------------------- Surcharge d'opérateurs
   bool TrajetCompose::operator == ( const Trajet * unTrajet) const
// Algorithme :
{
	const Trajet * traj= unTrajet;
	Trajet * unTraj = const_cast<Trajet*>(traj);
	if(TrajetCompose * trajCom = dynamic_cast<TrajetCompose*>(unTraj)){
		if(listeTrajet == trajCom->getterListeTrajet()){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
} //----- Fin de operator ==

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
ListOrd* llcopie = new ListOrd(*unTrajetCompose.getterListeTrajet());
listeTrajet=llcopie;
villeDepart = new char[20];
villeArrivee = new char[20];
strcpy(villeDepart, unTrajetCompose.getterVilleDepart());
strcpy(villeArrivee, unTrajetCompose.getterVilleArrivee());
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose (ListOrd * ll )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
listeTrajet = ll;
villeDepart = new char[20];
villeArrivee = new char[20];
strcpy(villeDepart, ll->head->current->getterVilleDepart());
strcpy(villeArrivee, ll->tail->current->getterVilleArrivee());
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
delete listeTrajet;
delete [] villeDepart;
delete [] villeArrivee;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
