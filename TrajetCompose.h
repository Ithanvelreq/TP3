/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ->

#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListOrd.h"
#include "Trajet.h"
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>:
// Gère, sous forme de liste, des trajets composés d'autres trajets soit
// simples soit composés aussi. Cette liste est ordonnée, la ville d'arrivée
// d'un trajet est la ville de départ du suivant.
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher (const char * mess = "TC") const;
    // Affiche les caractéristiques des trajets composant le tajet composé

    void Ecrire (std::ofstream &of, const char * msg = "ajouts") const;
    // Ecrit les caracteristiques d'un trajet composé dans un fichier

    ListOrd * getterListeTrajet () const;
    // Méthode permettant d'accéder à l'attribut protégé listeTrajets

//------------------------------------------------- Surcharge d'opérateurs
    bool operator == ( const Trajet * unTrajet )const;
    // Compare le trajet que l'on veut avec celui passé en paramètres
    // en vérifiant le type du trajet et en comparant la liste des trajets  

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    // Recopie la liste du trajet passé en paramètres et les villes
    // de départ et d'arrivée

    TrajetCompose (ListOrd * ll );
    // Construit un parcours composé des trajets présent dans la liste de
    // trajets ordonnée passée en paramètres

    virtual ~TrajetCompose ( );
    //Destructeur de la classe TrajetCompose
    //Libère l'espace mémoire alloué à la liste de trajets et aux
    //villes de départ et d'arrivée 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
ListOrd * listeTrajet; 
//Pointeur sur la liste de trajets composant un trajet composé

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // TRAJETCOMPOSE_H




