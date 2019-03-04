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

	private:

	public:

	// COMPLETAR


	Monomio & operator=(Monomio const &m);

	Monomio & operator=(double const &x);

	Monomio & operator+=(Monomio const &m);

	Monomio & operator-=(Monomio const &m);

	Monomio & operator*=(Monomio const &m);

	Monomio & operator*=(double const &x);

	Monomio & operator/=(Monomio const &m);

	Monomio & operator/=(double const &x);

	void leerMonomio();

	void escribirMonomio() const;


	}; // Fin de la definición de la clase Polinomio



}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
