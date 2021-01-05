/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) --->
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>:
// Gère des trajets directs avec un moyen de transport défini, d'une ville
// à une autre sans s'arrêter à une autre ville.
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher (const char * mess = "TS") const;
    // Affiche les caractéristiques d'un trajetSimple (villeDepart, 
    // villeArrivee et moyenTransport)

    void Ecrire (std::ofstream  &of, const char * msg = "ajouts") const;
    // Ecrit les caractéristiques du trajet simple dans le fichier of

    const char * getterMoyenTransport () const;
    // Méthode permettant d'accéder à l'attribut protégé moyenTransport

//------------------------------------------------- Surcharge d'opérateurs
    bool operator==(const Trajet * unTrajet) const;
    // Compare le type des trajets puis les villes de départ et 
    // d'arrivée ainsi que le moyen de transport

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple (const char * vd,const char* va,const char* mt );
    // Construit un trajet simple avec une ville de départ, une ville
    // d'arrivée et un moyen de transport

    TrajetSimple(const TrajetSimple & unTrajet);
    // Mode d'emploi (constructeur de copie) :
    // Copie les villes de départ et d'arrivée et le moyen de 
    // transport de unTrajet

    virtual ~TrajetSimple ( );
    // Libère l'espace mémoire alloué aux villes de départ et
    // d'arrivée et au moyen de transport

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char * moyenTransport;
//Pointeur sur le moyen de transport propre à un trajet simple
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSSIMPLE_H

