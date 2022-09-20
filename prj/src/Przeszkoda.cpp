#include "Przeszkoda.hh"
#include "Wektor3D.hh"

using namespace std;

void Przeszkoda::Inicjalizuj() {
  Punkt.push_back(Wektor3D(0, 0, 100));
  Punkt.push_back(Wektor3D(0, 0, -50)); 

  Punkt.push_back(Wektor3D(5, -90, 100));
  Punkt.push_back(Wektor3D(5, -90, -50));
  
  Punkt.push_back(Wektor3D(5, 90, 100));
  Punkt.push_back(Wektor3D(5, 90, -50));
 
  Punkt.push_back(Wektor3D(-5, 90, 100));
  Punkt.push_back(Wektor3D(-5, 90, -50));

  Punkt.push_back(Wektor3D(-5, -90, 100));
  Punkt.push_back(Wektor3D(-5, -90, -50));

  Srodek=(Wektor3D(0,0,25));

  SzerokoscX=10;
  DlugoscY=180;
  WysokoscZ=150;
  
  Punkt_globalny = Punkt;
}

void Przeszkoda::Inicjalizuj1() {

  Punkt.push_back(Wektor3D(0, 0, 100));
  Punkt.push_back(Wektor3D(0, 0, -50)); 

  Punkt.push_back(Wektor3D(60, -10, 100));
  Punkt.push_back(Wektor3D(60, -10, -50));
  
  Punkt.push_back(Wektor3D(60, 10, 100));
  Punkt.push_back(Wektor3D(60, 10, -50));
 
  Punkt.push_back(Wektor3D(-60, 10, 100));
  Punkt.push_back(Wektor3D(-60, 10, -50));

  Punkt.push_back(Wektor3D(-60, -10, 100));
  Punkt.push_back(Wektor3D(-60, -10, -50));

  Srodek=(Wektor3D(0,0,25));
  
  SzerokoscX=120;
  DlugoscY=20;
  WysokoscZ=150;
  
  Punkt_globalny = Punkt;
}
void Przeszkoda::Inicjalizuj2() {

  Punkt.push_back(Wektor3D(0, 0, 200));
  Punkt.push_back(Wektor3D(0, 0, -90)); 

  Punkt.push_back(Wektor3D(10, -10, 200));
  Punkt.push_back(Wektor3D(10, -10, -90));
  
  Punkt.push_back(Wektor3D(10, 10, 200));
  Punkt.push_back(Wektor3D(10, 10, -90));
 
  Punkt.push_back(Wektor3D(-10, 10, 200));
  Punkt.push_back(Wektor3D(-10, 10, -90));

  Punkt.push_back(Wektor3D(-10, -10, 200));
  Punkt.push_back(Wektor3D(-10, -10, -90));

  Srodek=(Wektor3D(0,0,55));
  
  SzerokoscX=20;
  DlugoscY=20;
  WysokoscZ=290;
  
  Punkt_globalny = Punkt;
}

void Przeszkoda::InicjalizujDane(Wektor3D wektor) {
  Wektor3D wek;

  cout << "Podaj wymiary przeszkody:";
  cin >> wek;
  
  SzerokoscX=wek[0];
  DlugoscY=wek[1];
  WysokoscZ=wek[2];
  
  
  Punkt.push_back(Wektor3D(wektor[0], wektor[1], wektor[2]+wek[2]/2));
  Punkt.push_back(Wektor3D(wektor[0], wektor[1], wektor[2]-wek[2]/2)); 

  Punkt.push_back(Wektor3D(wektor[0]+wek[0]/2, wektor[1]-wek[1]/2, wektor[2]+wek[2]/2));
  Punkt.push_back(Wektor3D(wektor[0]+wek[0]/2, wektor[1]-wek[1]/2, wektor[2]-wek[2]/2));
  
  Punkt.push_back(Wektor3D(wektor[0]+wek[0]/2, wektor[1]+wek[1]/2, wektor[2]+wek[2]/2));
  Punkt.push_back(Wektor3D(wektor[0]+wek[0]/2, wektor[1]+wek[1]/2, wektor[2]-wek[2]/2));
 
  Punkt.push_back(Wektor3D(wektor[0]-wek[0]/2, wektor[1]+wek[1]/2, wektor[2]+wek[2]/2));
  Punkt.push_back(Wektor3D(wektor[0]-wek[0]/2, wektor[1]+wek[1]/2, wektor[2]-wek[2]/2));

  Punkt.push_back(Wektor3D(wektor[0]-wek[0]/2, wektor[1]-wek[1]/2, wektor[2]+wek[2]/2));
  Punkt.push_back(Wektor3D(wektor[0]-wek[0]/2, wektor[1]-wek[1]/2, wektor[2]-wek[2]/2));
  
  Srodek=(wektor);

  Punkt_globalny = Punkt;
  

}


void Przeszkoda::Zapisz(std::ostream &Strm) {

    for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[0][j];
    }

    Strm << std::endl;

  for (long unsigned int i = 2; i < Punkt_globalny.size(); i++) {

    
    for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[i][j];
   }
   

if (i % 2 == 1 && i!=2)
      {
	Strm << std::endl;
	
    for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[1][j];
    }
    Strm << std::endl << std::endl;
      
    for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[0][j];
    }


      }

    
    Strm << std::endl;
  }

  for (int i = 2; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[i][j];
    }
    Strm << std::endl;
  }
  for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[0][j];
    }

  
}
Przeszkoda Przeszkoda::operator+(Wektor3D Arg2) {
  for (long unsigned int i = 0; i < Punkt.size(); ++i) {
    Punkt_globalny[i] += Arg2;
  }
  Wektor_Trans = Wektor_Trans + Arg2;
  Srodek += Arg2;
  return (*this);
}
void Przeszkoda::Przesun(Wektor3D Wek) {
  for (long unsigned int i = 0; i < Punkt_globalny.size(); ++i) {
    Punkt_globalny[i] += Wek;
  }
  Srodek += Wek;
  Wektor_Trans += Wek;
}
