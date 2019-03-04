/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:
     std::vector <Monomio> vector;
   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio
    inline Polinomio()
    {
      Monomio m;
      this->vector.push_back(m);
      #ifndef NDEBUG
        assert( this->esNulo() == true );
      #endif
    }

    inline Polinomio(const Polinomio &p)
    {
      this->vector = p.vector;
      #ifndef NDEBUG
        for(int i = 0; i < this->getNumeroMonomios(); i++)
        {
          assert( (this->vector[i].getGrado() == p.vector[i].getGrado()) and (std::abs(this->vector[i].getCoeficiente() - p.vector[i].getCoeficiente()) < COTA_ERROR) );
        }
      #endif
    }

  //! \name Observadores: funciones de consulta de la clase Polinomio
    inline bool esNulo()
    {
      for(int i = 0; i < this->getNumeroMonomios(); i++)
      {
        if( (std::abs(this->vector[i].getCoeficiente() - 0.0) < COTA_ERROR) || (this->vector[i].getGrado() != 0) )
        {
          return false;
        }
      }
      return true;
    }

    inline int getNumeroMonomios()
    {
      return this->vector.size();
    }
	// COMPLETAR


	//! \name Funciones de modificación de la clase Polinomio

	// COMPLETAR


 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);


	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

	// COMPLETAR


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
