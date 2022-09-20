#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x
all: __start__ clean
__start__: obroty_3D 
	./obroty_3D 

obroty_3D: obj obj/main.o obj/Prostopadloscian.o obj/Macierz3x3.o\
           obj/lacze_do_gnuplota.o obj/Obiekt_graf.o obj/Graniastoslup.o\
		   obj/Dron.o obj/Obsluga.o obj/Scena.o obj/ObiektSceny.o\
		   obj/Przeszkoda.o obj/FabrykaObiektow.o
	g++ -g -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o\
                        obj/Macierz3x3.o obj/Prostopadloscian.o obj/lacze_do_gnuplota.o\
						obj/Obiekt_graf.o obj/Graniastoslup.o obj/Dron.o obj/Obsluga.o \
						obj/Scena.o obj/ObiektSceny.o obj/Przeszkoda.o obj/FabrykaObiektow.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Macierz3x3.hh inc/Macierz.hh\
           inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh\
         inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Obiekt_graf.o: src/Obiekt_graf.cpp inc/Obiekt_graf.hh
	g++ -c ${CXXFLAGS} -o obj/Obiekt_graf.o src/Obiekt_graf.cpp

obj/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Obsluga.o: src/Obsluga.cpp inc/Obsluga.hh
	g++ -c ${CXXFLAGS} -o obj/Obsluga.o src/Obsluga.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/ObiektSceny.o: src/ObiektSceny.cpp inc/ObiektSceny.hh
	g++ -c ${CXXFLAGS} -o obj/ObiektSceny.o src/ObiektSceny.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

obj/FabrykaObiektow.o: src/FabrykaObiektow.cpp inc/FabrykaObiektow.hh
	g++ -c ${CXXFLAGS} -o obj/FabrykaObiektow.o src/FabrykaObiektow.cpp

clean:
	rm -f obj/*.o obroty_3D
	rm *.dat
	rmdir obj

