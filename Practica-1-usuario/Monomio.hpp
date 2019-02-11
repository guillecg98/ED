/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

	// COMPLETAR
	double coeficiente;
	int grado;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

	// COMPLETAR
	inline Monomio(double coeficiente = 0.0, int grado = 0)
	{
		#ifndef NDEBUG
			assert( grado >= 0 );
		#endif

		this->setCoeficiente(coeficiente);
		this->setGrado(grado);

		#ifndef NDEBUG
			assert( std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR );
			assert( this->getGrado() == grado);
		#endif
	}

	inline Monomio(const Monomio &m)
	{
		this->setCoeficiente(m.getCoeficiente());
		this->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert( std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR );
			assert( this->getGrado() == m.getGrado() );
		#endif
	}

	//! \name Observadores: funciones de consulta de la clase Monomio

	// COMPLETAR
	inline double getCoeficiente() const { return coeficiente; }
	inline int getGrado() const { return grado; }


	//! \name Funciones de modificación de la clase Monomio

	// COMPLETAR
	inline void setCoeficiente(double x)
	{
		coeficiente = x;

		#ifndef NDEBUG
			assert( std::abs(this->getCoeficiente() - x) < COTA_ERROR );
		#endif
	}

	inline void setGrado(int n)
	{
		#ifndef NDEBUG
			assert( n >= 0 );
		#endif

		grado = n;

		#ifndef NDEBUG
			assert( this->getGrado() == n );
		#endif
	}



	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator=(Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator+=(Monomio const &m);


		// COMPLETAR EL RESTO DE OPERADORES


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	// COMPLETAR



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
