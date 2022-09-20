#ifndef FABRYKAOBIEKTOW_HH
#define FABRYKAOBIEKTOW_HH
#include <memory>
#include "ObiektSceny.hh"
#include "Przeszkoda.hh"
#include "Dron.hh"


/*!
 * \brief Klasa modeluje pojecie FabrykiObiektow
 *
 * Klasa modeluje pojecie FabrykiObiektow
 */
class FabrykaObiektow
{
 public:
  /*!
   * \brief Metoda pozwala na dodawanie wybranego obiektu
   *
   * Metoda pozwala na dodawanie wybranego obiektu
   * \param rodzaj - rodzaj tworzonego obiektu
   */
  std::shared_ptr<ObiektSceny> StworzObiekt(int rodzaj);
};

#endif
