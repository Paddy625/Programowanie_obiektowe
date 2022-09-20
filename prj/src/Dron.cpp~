#include "Dron.hh"
#include <memory>

void Dron::Ruch(Wektor3D wek) {
    Korpus.Przesun(wek);
    for (int i = 0; i < ILOSC_ROTOROW; ++i) {
      Rotor[i].Przesun(wek);
    }
}

void Dron::Obrot(PzG::LaczeDoGNUPlota &Lacze, int NumerDrona) {
  double kat;
  std::cout << "Podaj kat obrotu: ";
  std::cin >> kat;
  Kat_Obrotu += kat;
  if (Kat_Obrotu >= 360)
    Kat_Obrotu -= 360;
  else if (Kat_Obrotu <= -360)
    Kat_Obrotu += 360;

  for (int klatka = 0; klatka < abs(kat); ++klatka) {
    Korpus.Obrot(1);
    for (int i = 0; i < ILOSC_ROTOROW; ++i) {
      Rotor[i].Obrot(1);
    }

    this->Animacja(Lacze, NumerDrona);
    this->Zapisz(NumerDrona);
    Lacze.Rysuj();
    usleep(20000);
  }
}

void Dron::Zapisz(int NumerDrona) {
  std::fstream PlikWy;
  std::string NazwaPliku;
  NazwaPliku = "Korpus";
  NazwaPliku.append(std::to_string(NumerDrona));
  NazwaPliku.append(".dat");
  PlikWy.open(NazwaPliku, std::fstream::out);
  Korpus.Zapisz(PlikWy);
  PlikWy.close();
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    NazwaPliku = "Rotor";
    NazwaPliku.append(std::to_string(NumerDrona));
    NazwaPliku.append("_");
    NazwaPliku.append(std::to_string(i));
    NazwaPliku.append(".dat");
    PlikWy.open(NazwaPliku, std::fstream::out);
    Rotor[i].Zapisz(PlikWy);
    PlikWy.close();
  }
}

void Dron::Inicjalizuj() {
  Korpus.Inicjalizuj();
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    Rotor[i].Inicjalizuj();
  }
  Rotor[0].UstawPolozenie(Wektor3D(20, 20, 20));
  Rotor[1].UstawPolozenie(Wektor3D(20, -20, 20));
  Rotor[2].UstawPolozenie(Wektor3D(-20, 20, 20));
  Rotor[3].UstawPolozenie(Wektor3D(-20, -20, 20));
  Aproksymacja.punkt_srodka=Srodek;
}

void Dron::Animacja(PzG::LaczeDoGNUPlota &Lacze, int NumerDrona) {
  AktualizujRotory();
  Rotor[0].ObrotSmigiel(10);
  Rotor[1].ObrotSmigiel(-10);
  Rotor[2].ObrotSmigiel(-10);
  Rotor[3].ObrotSmigiel(10);

  this->Zapisz(NumerDrona);
  Lacze.Rysuj();
  usleep(1000);
}

void Dron::AktualizujRotory() {
    Rotor[0].UstawOffset(Korpus[5]);
    Rotor[1].UstawOffset(Korpus[3]);
    Rotor[2].UstawOffset(Korpus[7]);
    Rotor[3].UstawOffset(Korpus[9]);
}

void Dron::Przesun(Wektor3D przesuniecie) {
  Korpus.Przesun(przesuniecie);
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    Rotor[i].Przesun(przesuniecie);
  }
  Aproksymacja.punkt_srodka=Srodek;
}
