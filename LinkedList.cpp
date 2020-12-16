/*************************************************************************
                           LinkedList  -  description
                             -------------------
    début                : 25/11/2020
    copyright            : (C) 2020 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LinkedList> (fichier LinkedList.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LinkedList.h"
#include "Data.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void LinkedList::Ajouter(const Trajet * unTrajet)
{
        Data * d = new Data(unTrajet);
        if(!head){
                head = d;
        }
        if(!tail){
                tail = d;
        }else{
                tail->next = d;
                tail = d;
        }
}//Fin de Ajouter


void LinkedList::Afficher(const char * mess /* = ""*/) const
{
        Data * c = head;
	int first = 0;
        while(c != NULL) {
		const Trajet * pq = c->current;
		if(!strcmp("TC", mess) && first == 0){
			pq->Afficher("TC");
		}else if (!strcmp("TC", mess) && (c ->next) == NULL){
			pq->Afficher("fini");
		}else if (!strcmp("TC", mess)){
			pq->Afficher("then");
		}else if (strcmp("TS", mess)){
			pq->Afficher("TS");
		}else{
			pq->Afficher();	
		}
                c = c -> next;
		first = 1;
        }
}//Fin de Afficher

bool LinkedList::operator==(const LinkedList & ll)const
{
        Data * c1 = head;
        Data * c2 = ll.head;
        while(c1 != NULL && c2 != NULL) {
                if(!(*(c1 -> current) == (c2 -> current) )){
                        return false;
                }
                c1 = c1 -> next;
                c2 = c2 -> next;
        }
        if(c1 != NULL || c2 != NULL){
                return false;
        }
        return true;
}//Fin de operator==

bool LinkedList::Contains(const Trajet * unTrajet) const
{
        Data * c = head;
        while(c != NULL) {
                if(*(c -> current) == unTrajet){
                        return true;
                }
                c = c -> next;
        }
        return false;
}//Fin de Contains

//-------------------------------------------- Constructeurs - destructeur
LinkedList::LinkedList()
{       
        #ifdef MAP
                cout << "Appel au constructeur de <LinkedList>" << endl;
        #endif
        head = NULL;
        tail = NULL;
        
} //----- Fin de LinkedList

LinkedList::LinkedList(const LinkedList & ll)
{
        #ifdef MAP
                cout << "Appel au destructeur de copie de <LinkedList>" << endl;
        #endif
        head = NULL;
        tail = NULL;

        Data *c = ll.head;
        while(c != NULL){
                const Trajet * traj = c->current;

                //creer copie de c->current
                Trajet * unTraj = const_cast<Trajet*>(traj);
                if(TrajetSimple * test = dynamic_cast<TrajetSimple*>(unTraj)){
                        TrajetSimple * trajA = new TrajetSimple(*test);
                        Ajouter(trajA);
                }else if(TrajetCompose* test = dynamic_cast<TrajetCompose*>(unTraj)){
                        TrajetCompose * trajA = new TrajetCompose(*test);
                        Ajouter(trajA);
                }
                c = c -> next;
        }
}//Fin de LinkedList (constructeur de copie)

LinkedList::~LinkedList()
{       
        #ifdef MAP
                cout << "Appel au destructeur de <LinkedList>" << endl;
        #endif
        Data * c1 = head;
        Data * c2 = c1;
        while(c1 != NULL) {
                c2 = c1 -> next; 
                delete c1;
                c1 = c2;
        }
} //----- Fin de ~LinkedList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


