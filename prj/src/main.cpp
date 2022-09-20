#include "Obsluga.hh"
#include "Scena.hh"
#include "lacze_do_gnuplota.hh"
#include "FabrykaObiektow.hh"

using namespace std;

int main() {
  PzG::LaczeDoGNUPlota Lacze;
  Scena sc;
  char wybor;
  int i=1, p=0, d=3;
  FabrykaObiektow Fabryka;
  
  UstawLacze(Lacze, d); 
  WyswietlLiczniki();
  WyswietlMenu();
  sc.Inicjalizuj(Lacze);
  WyswietlLiczniki();
  WyswietlNumer(sc.Indeks(), sc.ZwrocDrona()->ZwrocSrodek());
  Lacze.Inicjalizuj();
  Lacze.Rysuj();

  
  while (i) {
    cin >> wybor;
    switch (wybor) {
    case 'o': {
      sc.ZwrocDrona()->Obrot(Lacze, sc.Indeks());

      Lacze.Rysuj();
      break;
    }
    case 'j': {
      Ruch(Lacze, sc.Indeks(), sc);
      Lacze.Rysuj();
      break;
    }
    case 's': {
      sc.ZmienDrona();
      WyswietlNumer(sc.Indeks(), sc.ZwrocDrona()->ZwrocSrodek());
      break;
    }
    case 'w': {
      WyswietlMenu();
      break;
    }
    case 'p': {
      sc.Dodaj(Fabryka.StworzObiekt(0), p, Lacze, 0); //Stworzenie przeszkody
      p++;
      Lacze.Rysuj();
      break;
    }
    case 'd':{
      sc.Dodaj(Fabryka.StworzObiekt(1), d, Lacze, 1); //Stworzenie drona
      d++;
      UstawLacze(Lacze, d);
      Lacze.Rysuj();
      break;
    }
    case 'k': {
      i=0;
      break;
    }
    }
  }
  WyswietlLiczniki();
  return 0;
}
 

