#include "Scena.hh"
#include "Przeszkoda.hh"

using namespace std;

void InicjalizujDrona(shared_ptr<ObiektSceny> dron,
		      int Indeks){
  dron->Inicjalizuj();
  dron->Przesun(Wektor3D(Indeks * 60 + 10, Indeks * 60 + 10, Indeks * 40 + 10));
  dron->Zapisz(Indeks);
}
void InicjalizujPrzeszkode(shared_ptr<ObiektSceny> przeszkoda,
			   int Indeks, int jIndeks,
			   PzG::LaczeDoGNUPlota Lacze){
  fstream PlikWy;
  string NazwaPliku;
  NazwaPliku = "Przeszkoda";
  NazwaPliku.append(to_string(Indeks));
  NazwaPliku.append(".dat");
  PlikWy.open(NazwaPliku, fstream::out);
 
 switch(Indeks){
 case 3: {
   przeszkoda->Inicjalizuj();
   przeszkoda->Przesun(Wektor3D(270, 100, -50));
   break;
 }
 case 4: {
   przeszkoda->Inicjalizuj1();
   przeszkoda->Przesun(Wektor3D(200, 200, 0));
  break;
 }
 case 5: {
   przeszkoda->Inicjalizuj2();
   przeszkoda->Przesun(Wektor3D(50, 200, 0));
   break;
 }
 }
  przeszkoda->Zapisz(PlikWy);
  Lacze.DodajNazwePliku(NazwaPliku.c_str());
 }

void Scena::StworzListeDrony(){
  for (int i = 0; i < ILOSC_DRONOW; ++i) {
    shared_ptr<Dron> dron;

    dron = make_shared<Dron>();
    Drony.push_back(dron);
    Obiekty.push_back(dron);
  }
}
void Scena::StworzListeObiekty(){
  
  for (int i = 0; i < ILOSC_PRZESZKOD; ++i) {
    shared_ptr<Przeszkoda> przeszkoda;
    
    przeszkoda = make_shared<Przeszkoda>();
    Obiekty.push_back(przeszkoda);
  }
}
  

void Scena::Inicjalizuj(PzG::LaczeDoGNUPlota &Lacze) {
  StworzListeDrony();
  StworzListeObiekty();
  
  int i = 0, j = 5;
  for (shared_ptr<ObiektSceny> obiekt : Obiekty) {
    switch (obiekt->ID()) {
    case 1: {
      InicjalizujDrona(obiekt,i);
      break;
    }
    case 0: {
      InicjalizujPrzeszkode(obiekt,i,j,Lacze);
      break;
    }
    }
    ++i;
    --j;
  }
  ItDrony = Drony.begin();
  ItObiekty = Obiekty.begin();
}

void InicjalizujDrona2(shared_ptr<ObiektSceny> dron,
		      int Indeks){
  Wektor3D wek;
  dron->Inicjalizuj();
  cout << "Podaj polozenie drona: ";
  cin >> wek;
  wek[2] = wek[2]-10;
  dron->Przesun(wek);
  dron->Zapisz(Indeks);  
}


void InicjalizujPrzeszkode2(shared_ptr<ObiektSceny> przeszkoda, int Indeks,
			    PzG::LaczeDoGNUPlota Lacze){
  fstream PlikWy;
  string NazwaPliku;
  Wektor3D wek;
  
  NazwaPliku = "Przeszkoda";
  NazwaPliku.append(to_string(Indeks));
  NazwaPliku.append(".dat");
  PlikWy.open(NazwaPliku, fstream::out);
 
 
  cout << "Podaj wspolrzedne:";
  cin >> wek;

  przeszkoda->InicjalizujDane(wek);

  przeszkoda->Zapisz(PlikWy);
  Lacze.DodajNazwePliku(NazwaPliku.c_str());
  }


void Scena::Dodaj(std::shared_ptr<ObiektSceny> Obiekt, int Indeks, PzG::LaczeDoGNUPlota &Lacze,
		  int rodzaj)
{
  switch(rodzaj){
  case 0:{
    InicjalizujPrzeszkode2(Obiekt, Indeks, Lacze);
    Obiekty.push_back(Obiekt);
    break;
 }
  case 1:{
    InicjalizujDrona2(Obiekt, Indeks);
    Drony.push_back(static_pointer_cast<Dron>(Obiekt));
    Obiekty.push_back(Obiekt);
    break;
  }   
  }
}


void Scena::ZmienDrona() {
  ItDrony = next(ItDrony);
  if (ItDrony == Drony.end()) {
    ItDrony = Drony.begin();
  }
}

void Scena::ZmienObiekt() {
  ItObiekty = next(ItObiekty);
  if (ItObiekty == Obiekty.end()) {
    ItObiekty = Obiekty.begin();
  }
}

bool Scena::CzyKolizja(std::shared_ptr<ObiektSceny> AktualnyDron) {
  for (std::shared_ptr<ObiektSceny> obiekt : Obiekty) {
    if (AktualnyDron == obiekt){}
    else if (obiekt->CzyKolizja(AktualnyDron)) return true;
  }
  return false;
}


