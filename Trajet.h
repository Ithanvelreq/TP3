/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------->
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>:
// Classe abstraite dont les classes TrajetSimple et TrajetCompose heritent
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Afficher (const char * mess = "T") const = 0;
    // Méthode redéfinie dans les classes filles

    virtual const char * getterVilleDepart () const;
    // Méthode permettant d'accéder à l'attribut protégé villeDepart

    virtual const char * getterVilleArrivee () const;
    // Méthode permettant d'accéder à l'attribut protégé villeArrivee

//------------------------------------------------- Surcharge d'opérateurs
    virtual bool operator == ( const Trajet * unTrajet )const = 0;
    // Méthode redéfinie dans les classes filles

//-------------------------------------------- Constructeurs - destructeur
/*    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/

    /* Trajet ();*/
    // Mode d'emploi :
    // Constructeur par défault
    // Contrat :
    //


    virtual ~Trajet ( );
    // Mode d'emploi :

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
char * villeDepart;
char * villeArrivee;
//Pointeur sur les villes de départ et d'arrivée propres à chaque trajet
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H


