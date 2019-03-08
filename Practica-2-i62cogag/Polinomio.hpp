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
#include "operadoresExternosMonomios.hpp"


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
          assert( (this->vector[i] == p.vector[i]) );
        }
      #endif
    }

  //! \name Observadores: funciones de consulta de la clase Polinomio
    inline bool esNulo() const
    {
      for(int i = 0; i < this->getNumeroMonomios(); i++)
      {
        if( this->vector[i] == 0.0 )
        {
          return true;
        }
      }
      return false;
    }

    inline int getGrado() const
    {
      return this->vector.front().getGrado(); //devuelve el grado del primer elemento que deberia ser el de mayor grado cuando esté ordenado
    }

    inline int getNumeroMonomios() const
    {
      return this->vector.size();
    }

    inline bool existeMonomio(int n) const
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
      #endif

      for(int i = 0; i < this->getNumeroMonomios(); i++)
      {
        if(this->vector[i].getGrado() == n)
        {
          return true;
        }
      }
      return false;
    }

    inline int getPosicion(int n) const
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
        assert( this->existeMonomio(n) == true );
      #endif

      for(int i = 0; i < this->getNumeroMonomios(); i++)
      {
        if(this->vector[i].getGrado() == n)
        {
          return i;
        }
      }
      return 0;
    }

    inline Monomio getMonomio(int n) const
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
        assert( this->getPosicion(n) == true );
      #endif

      return this->vector[this->getPosicion(n)];
    }

    //funcion extra: comprueba si un polinomio está ordenado
    inline bool isOrdered() const
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
      #endif

      for( int i = 0; i < this->getNumeroMonomios()-1; i++)
      {
        if( this->vector[i].getGrado() <= this->vector[i+1].getGrado() )
        {
          return false;
        }
      }
      return true;
    }
	// COMPLETAR


	//! \name Funciones de modificación de la clase Polinomio
  //funcion extra: ordena un polinomio desordenado y suma aquellos monomios con mismo grado
  void ordenaPolinomio();
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
