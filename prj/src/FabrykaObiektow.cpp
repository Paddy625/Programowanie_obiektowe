#include "FabrykaObiektow.hh"

std::shared_ptr<ObiektSceny> FabrykaObiektow::StworzObiekt(int rodzaj)
{
  switch(rodzaj){
    case 0:{
      return std::make_shared<Przeszkoda>();
      
    }
    case 1:{
      return std::make_shared<Dron>();
    }
    }
    return nullptr;
}
