#include <iostream>
#include <cstring>
#include <fstream>
#include "LinkedList.h"
#include "ListOrd.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#define TAILLE 20
using namespace std;

int main(){
	char * command = new char[TAILLE];
	char * va = new char[TAILLE];
	char * vd = new char[TAILLE];
	char * mt = new char[TAILLE];
	char * fichier = new char [TAILLE];
	char * typetraj = new char [TAILLE];
	char * vaselected = new char [TAILLE];
	char * vdselected = new char [TAILLE];
	bool load = false;
	bool addts = true;
	bool addtc = true;
	bool selva = false;
	bool selvd = false;
	ifstream is;
	ofstream os;
	Catalogue catalog;
	cin.getline(command, TAILLE);
	while(strcmp(command, "bye") != 0){
		if(!strcmp(command, "ajouts")){
			//Ajout d un trajet simple
			if(load){
				is.getline(vd, TAILLE, ' ');
				is.getline(va, TAILLE, ' ');
				is.getline(mt, TAILLE);
			}else{
				cin.getline(vd, TAILLE, ' ');
				cin.getline(va, TAILLE, ' ');
				cin.getline(mt, TAILLE);
			}
			if(addts && (!strcmp(vaselected, va) || !selva) && (!strcmp(vdselected, vd) || !selvd)){
				TrajetSimple * traj = new TrajetSimple(vd, va, mt);
				catalog.Ajouter(traj);
				cout << "Trajet simple ajoute: ";
				traj ->Afficher();
			}
		}else if(!strcmp(command, "ajoutc")){
			//Ajout d un trajet compose
			ListOrd *ll;
			if(addtc){
				ll = new ListOrd();
			}	
			while(strcmp(command, "fini") != 0){
				if(load){
					is.getline(vd, TAILLE, ' ');
                                        is.getline(va, TAILLE, ' ');
					is.getline(mt, TAILLE, ' ');
					is.getline(command, TAILLE);
				}else{
					cin.getline(vd, TAILLE, ' ');
					cin.getline(va, TAILLE, ' ');
					cin.getline(mt, TAILLE, ' ');
					cin.getline(command, TAILLE);
				}
				if(addtc){
					TrajetSimple* traj = new TrajetSimple(vd, va, mt);
					ll->Ajouter(traj);
				}
			}
			if(addtc){
				TrajetCompose * tc = new TrajetCompose(ll);
				if((!strcmp(vaselected, tc->getterVilleArrivee()) || !selva) && (!strcmp(vdselected, tc->getterVilleDepart()) || !selvd)){
					cout << "Trajet compose ajoute: ";
					tc -> Afficher();
					catalog.Ajouter(tc);
				}else{
					delete tc;
				}
			}
		}else if(!strcmp(command, "afficher")){
			//Affichage du catalogue
			catalog.Afficher();
		}else if(!strcmp(command, "recherches")){
			//recherche simple dans le catalogue
			cin.getline(vd, TAILLE, ' ');
			cin.getline(va, TAILLE);
			cout << "Les resultats de la recherche simple sont"<<endl;
			catalog.Recherches(vd, va);
		}else if(!strcmp(command, "recherchea")){
			//recherche avancee dans le catalogue
			cin.getline(vd, TAILLE, ' ');
			cin.getline(va, TAILLE);
			cout << "Les resultats de la recherche avance sont"<<endl;
			catalog.Recherchea(vd, va);
		}else if(!strcmp(command, "load")){
			cin.getline(fichier, TAILLE, ' ');
			cin.getline(typetraj, TAILLE, ' ');
			cin.getline(vdselected, TAILLE, ' ');
			cin.getline(vaselected, TAILLE);
			is.open(fichier);
			if(is.is_open()){
				load = true;
			
				if(!strcmp(typetraj, "TC")){
					addts = false;
				}else if(!strcmp(typetraj, "TS")){
					addtc = false;
				}
				if(strcmp(vdselected, "*")!=0){
					selvd = true;
				}
				if(strcmp(vaselected, "*")!=0){
					selva = true;
				}
			}else{
				cout << "il y a eu une erreur pendant l'ouverture du fichier, veuillez ressayer a nouveau" << endl;
			}
		}else if(!strcmp(command, "save")){
			cin.getline(fichier, TAILLE, ' ');
			cin.getline(typetraj, TAILLE, ' ');
			cin.getline(vdselected, TAILLE, ' ');
			cin.getline(vaselected, TAILLE);
			os.open(fichier);
			if(os.is_open()){
				catalog.Ecrire(os, typetraj, vdselected, vaselected);
			}else{
				cout << "il y a eu une erreur pendant l'ouverture du fichier, veuillez ressayer a nouveau" << endl;
			}
			os.close();
		}
		if(is.peek() == EOF){
			load = false;
			addtc = true;
			addts = true;
			is.close();
		}
		if(load){
			is.getline(command, TAILLE); 
		}else{
			cin.getline(command, TAILLE);
		}
	}
	delete [] command;
	delete [] va;
	delete [] vd;
	delete [] mt;
	delete [] fichier;
	delete [] typetraj;
	delete [] vaselected;
	delete [] vdselected;
}
