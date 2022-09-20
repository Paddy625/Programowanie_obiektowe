#ifndef OBIEKT_SCENY_HH
#define OBIEKT_SCENY_HH
#include <memory>
#include "Walec.hh"
/*!
 * \brief Klasa modeluje pojecie Obiektu bedacego czescia sceny
 *
 * Klasa modeluje pojecie Obiektu bedacego czescia sceny. Jest to dron oraz
 * przeszkoda
 */
class ObiektSceny {
  static int IloscIstniejacych;
  static int IloscStworzonych;

 protected:
  /*!
   * \brief Pole sluzy do identyfikacji klasy pochodnej
   *
   * Pole sluzy do identyfikacji klasy pochodnej\n
   * 0-Przeszkoda\n
   * 1-Dron\n
   */
  int TypID;
  /*!
   * \brief Pole przechowuje wspolrzedne srodka obiektu
   *
   * Pole przechowuje wspolrzedne srodka obiektu w globalnym ukladzie
   * wspolrzednych
   */
  Walec Aproksymacja;
  /*!
   * \brief Pole przechowuje informacje o tym jak szeroka jest figura w
   * plaszczyznie X
   */
public:
  Wektor3D Srodek;
  /*!
   * \brief Pole przechowuje dane walca aproksymujacego obwod drona
   *
   * Pole przechwouje strukture Walec, ktora zawiera promien, wysokosc oraz
   * punkt srodka aproksymacji obwodu drona
   */

  double SzerokoscX;
  /*!
   * \brief Pole przechowuje informacje o tym jak dluga jest fiura w
   * plaszczyznie Y
   */
  double DlugoscY;
  /*!
   * \brief Pole przechowuje informacje o tym jak wysoka jest figura w
   * plaszczyznie Z
   */
  double WysokoscZ;
  

  ObiektSceny() {
    ++IloscIstniejacych;
    ++IloscStworzonych;
  }
  ~ObiektSceny() { --IloscIstniejacych; }
  ObiektSceny(ObiektSceny const &obj){ ++IloscIstniejacych; }

  static int ZwrocIloscIstniejacych() { return IloscIstniejacych; }
  static int ZwrocIloscStworzonych() { return IloscStworzonych; }
  /*!
   * \brief Metoda pozwala na zwrocenie pola TypID
   *
   * Metoda pozwala na zwrocenie pola TypID
   * \return wartosc TypID
   */
  virtual int ID() const { return TypID; }
  /*!
   * \brief Metoda pozwala na wybor odpowiedniej metody zapisu w klasach
   * pochodnych
   *
   *  Metoda pozwala na wybor odpowiedniej metody zapisu w klasach pochodnych
   */
  virtual void Zapisz(int Numer) {}
  /*!
   * \brief Metoda pozwala na wybor odpowiedniej metody zapisu w klasach
   * pochodnych
   *
   *  Metoda pozwala na wybor odpowiedniej metody zapisu w klasach pochodnych
   */
  virtual void Zapisz(std::ostream &Strm) {}
  /*!
   * \brief Metoda pozwala na uzyskanie dostepu do metody Inicjalizuj w klasach
   * pochodnych
   *
   * Metoda pozwala na uzyskanie dostepu do metody Inicjalizuj w klasach
   * pochodnych
   */
  virtual void Inicjalizuj() {}
  
  virtual void Inicjalizuj1() {}
  
  virtual void Inicjalizuj2() {}

  virtual void InicjalizujDane(Wektor3D wektor) {}

  /*!
   * \brief Metoda pozwala na uzyskanie dostepu do metody Przesun w klasach
   * pochodnych
   *
   * Metoda pozwala na uzyskanie dostepu do metody Przesun w klasach
   * pochodnych
   */
  virtual void Przesun(Wektor3D wektor) {}
  /*!
   * \brief Metoda zwraca wartosc pola Srodek
   *
   * Metoda zwraca wartosc pola Srodek
   * \return Wartosc pola Srodek
   */
  virtual Wektor3D ZwrocSrodek() { return Srodek; }
  /*!
   * \brief Metoda sprawdza czy przekazany do niej ObiektSceny koliduje z danym
   * obiektem
   *
   * Metoda sprawdza czy przekazany do niej ObiektSceny koliduje z danym
   * obiektem.
   * \param[in] AktualnyDron - Wskaznik do klasy ObiektSceny do
   * sprawdzenia czy nastapila z nim kolizja
   * \retval true - obiekty koliduja ze soba
   * \retval false - obiekty nie koliduja ze soba
   */
  bool CzyKolizja(std::shared_ptr<ObiektSceny> AktualnyDron);
};

#endif
