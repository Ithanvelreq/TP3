#include <iostream>
#include <cstring>
#include "LinkedList.h"
#include "ListOrd.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
using namespace std;

int main(){
	char * command = new char[20];
	char * va = new char[20];
	char * vd = new char[20];
	char * mt = new char[20];
	Catalogue catalog;
	cin.getline(command, 20);
	while(strcmp(command, "bye") != 0){
		if(!strcmp(command, "ajouts")){
			//Ajout d un trajet simple
			cin.getline(vd, 20, ' ');
			cin.getline(va, 20, ' ');
			cin.getline(mt, 20);
			TrajetSimple * traj = new TrajetSimple(vd, va, mt);
			catalog.Ajouter(traj);
			cout << "Trajet simple de " << vd << " a " << va << " en " << mt <<" ajoute"<< endl;
		}else if(!strcmp(command, "ajoutc")){
			//Ajout d un trajet compose
			ListOrd* ll = new ListOrd();
			cout << "Trajet composee";	
			while(strcmp(command, "fini") != 0){
				cin.getline(vd, 20, ' ');
				cin.getline(va, 20, ' ');
				cin.getline(mt, 20, ' ');
				TrajetSimple* traj = new TrajetSimple(vd, va, mt);
				ll->Ajouter(traj);
				cin.getline(command, 20);
				cout << " de " << vd << " a " << va << " en " << mt << " -";
			}
			cout<<" ajoute"<<endl;
			TrajetCompose * tc = new TrajetCompose(ll);
			catalog.Ajouter(tc);
		}else if(!strcmp(command, "afficher")){
			//Affichage du catalogue
			catalog.Afficher();
		}else if(!strcmp(command, "recherches")){
			//recherche simple dans le catalogue
			cin.getline(vd, 20, ' ');
			cin.getline(va, 20);
			cout << "Les resultats de la recherche simple sont"<<endl;
			catalog.Recherches(vd, va);
		}else if(!strcmp(command, "recherchea")){
			//recherche avancee dans le catalogue
			cin.getline(vd, 20, ' ');
			cin.getline(va, 20);
			cout << "Les resultats de la recherche avance sont"<<endl;
			catalog.Recherchea(vd, va);
		}
		cin.getline(command, 20, '\n');
	}
	delete [] command;
	delete [] va;
	delete [] vd;
	delete [] mt;
}
