#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include "Prostopadloscian.hh"
/*!
 * \brief Klasa modeluje pojecie przeszkody jako prostopadloscianu.
 *
 * Klasa modeluje pojecie przeszkody jako prostopadloscianu bedacego obiektem na
 * scenie.
 */
class Przeszkoda : public ObiektSceny {
  /*!
   *\brief Pole przechowuje oryginalne punkty poszczegolnych wierzcholkow
   *
   * Pole przechowuje oryginalne punkty poszczegolnych wierzcholkow
   */
  std::vector<Wektor3D> Punkt;
  /*!
   *\brief Pole przechowuje punkty poszczegolnych wierzcholkow w
   * globalnym ukladzie odniesienia
   *
   * Pole przechowuje punkty poszczegolnych wierzcholkow w
   * globalnym ukladzie odniesienia
   */
  std::vector<Wektor3D> Punkt_globalny;
  /*!
   *\brief Pole przechowuje wektor o jaki sa przesuniete wierzcholki w
   * stosunku do lokalnego ukladu odniesienia.
   *
   * Pole przechowuje wektor o jaki sa przesuniete wierzcholki w
   * stosunku do lokalnego ukladu odniesienia.
   */
  Wektor3D Wektor_Trans = Wektor3D();
  /*!
   *\brief Pole przechowuje kat o jaki figura jest obrocona
   *
   * Pole przechowuje kat o jaki figura jest obrocona.
   */
  double KatObrotu = 0;

 public:
  Przeszkoda() { TypID = 0; }
  Wektor3D ZwrocSrodek() { return Srodek; }
  void Inicjalizuj();
  void Inicjalizuj1();
  void Inicjalizuj2();
  void InicjalizujDane(Wektor3D wektor);
  void Zapisz(std::ostream &Strm);
  Przeszkoda operator+(Wektor3D Arg2);
  void Przesun(Wektor3D Wek);
};
#endif
