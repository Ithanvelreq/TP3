Main: TrajetSimple.o Trajet.o LinkedList.o Data.o TrajetCompose.o Catalogue.o ListOrd.o Main.o
	g++ -g -o Main TrajetSimple.o Main.o Trajet.o LinkedList.o Data.o TrajetCompose.o Catalogue.o ListOrd.o

Catalogue.o: Catalogue.cpp Catalogue.h LinkedList.cpp LinkedList.h Data.h Data.cpp TrajetSimple.cpp TrajetSimple.h TrajetCompose.h TrajetCompose.cpp Trajet.h Trajet.cpp
	g++ -g -c Catalogue.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.cpp Trajet.h
	g++ -g -c TrajetCompose.cpp

ListOrd.o: ListOrd.cpp ListOrd.h LinkedList.cpp LinkedList.h Data.cpp Data.h
	g++ -g -c ListOrd.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Data.cpp Data.h
	g++ -g -c LinkedList.cpp

Data.o: Data.h Data.cpp
	g++ -g -c Data.cpp

Main.o:Catalogue.cpp Catalogue.h TrajetSimple.h TrajetSimple.cpp TrajetCompose.cpp TrajetCompose.h Main.cpp
	g++ -g -c Main.cpp

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h Trajet.cpp
	g++ -g -c TrajetSimple.cpp

Trajet.o: Trajet.cpp Trajet.h
	g++ -g -c Trajet.cpp
