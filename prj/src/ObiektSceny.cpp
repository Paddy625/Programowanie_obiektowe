#include "ObiektSceny.hh"
#define PR_DRONA 40
#define WYS_DRONA 20

int ObiektSceny::IloscIstniejacych=0;
int ObiektSceny::IloscStworzonych=0;

bool ObiektSceny::CzyKolizja(std::shared_ptr<ObiektSceny> AktualnyDron) {
  double Xmax = this->Srodek[0] + PR_DRONA + this->SzerokoscX/2;
  double Xmin = this->Srodek[0] - PR_DRONA - this->SzerokoscX/2;
  
  double Ymax = this->Srodek[1] + PR_DRONA + this->DlugoscY/2;
  double Ymin = this->Srodek[1] - PR_DRONA - this->DlugoscY/2;
  
  double Zmax = this->Srodek[2] + WYS_DRONA + this->WysokoscZ/2;
  double Zmin = this->Srodek[2] - WYS_DRONA - this->WysokoscZ/2;

  if (Xmin <= AktualnyDron->ZwrocSrodek()[0] &&
      Xmax >= AktualnyDron->ZwrocSrodek()[0] &&

      Ymin <= AktualnyDron->ZwrocSrodek()[1] &&
      Ymax >= AktualnyDron->ZwrocSrodek()[1] &&
      
      Zmin <= AktualnyDron->ZwrocSrodek()[2] &&
      Zmax >= AktualnyDron->ZwrocSrodek()[2]   )
    {
      return true;
    }
  else  
    {
      return false;
    }
}
