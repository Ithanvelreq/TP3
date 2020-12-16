Main: Main.o TrajetSimple.o Trajet.o LinkedList.o Data.o TrajetCompose.o Catalogue.o ListOrd.o
	g++ -o Main TrajetSimple.o Main.o Trajet.o LinkedList.o Data.o TrajetCompose.o Catalogue.o ListOrd.o

Catalogue.o: Catalogue.cpp Catalogue.h LinkedList.cpp LinkedList.h Data.h Data.cpp TrajetSimple.cpp TrajetSimple.h TrajetCompose.h TrajetCompose.cpp Trajet.h Trajet.cpp
	g++ -c -Wall Catalogue.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.cpp Trajet.h
	g++ -c -Wall TrajetCompose.cpp

ListOrd.o: ListOrd.cpp ListOrd.h LinkedList.cpp LinkedList.h Data.cpp Data.h
	g++ -c -Wall ListOrd.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Data.cpp Data.h
	g++ -c -Wall LinkedList.cpp

Data.o: Data.h Data.cpp
	g++ -c -Wall Data.cpp

Main.o:Catalogue.cpp Catalogue.h TrajetSimple.h TrajetSimple.cpp TrajetCompose.cpp TrajetCompose.h Main.cpp
	g++ -c -Wall Main.cpp

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h Trajet.cpp
	g++ -c -Wall TrajetSimple.cpp

Trajet.o: Trajet.cpp Trajet.h
	g++ -c -Wall Trajet.cpp
