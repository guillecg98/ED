/*!
	\file operadoresExternosPolinomios.hpp
	\brief Ficheros con operadores de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

////////////////////////////////////////////////////////////////////////////
	// Funciones y operadores que no pertenecen a la clase Polinomio


	////////////////////////////////////////////////////////////
	//! \name Operadores de igualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2);
	bool operator==(ed::Polinomio const &p, Monomio const &m);
	bool operator==(Monomio const &m, ed::Polinomio const &p);
	bool operator==(ed::Polinomio const &p, double const &x);
	bool operator==(double const &x, ed::Polinomio const &p);

	////////////////////////////////////////////////////////////////////////////////////
	//! \name Operadores de desigualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2);
	bool operator!=(ed::Polinomio const &p, Monomio const &m);
	bool operator!=(Monomio const &m, ed::Polinomio const &p);
	bool operator!=(ed::Polinomio const &p, double const &x);
	bool operator!=(double const &x, ed::Polinomio const &p);

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores unarios

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		ed::Polinomio & operator+(ed::Polinomio const & p);
		ed::Polinomio & operator-(ed::Polinomio const & p);


//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la suma

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2);
		ed::Polinomio & operator+(ed::Polinomio const &p, Monomio const &m);
		ed::Polinomio & operator+(Monomio const &m, ed::Polinomio const &p);
		ed::Polinomio & operator+(ed::Polinomio const &p, double const &x);
		ed::Polinomio & operator+(double const &x, ed::Polinomio const &p);



		//////////////////////////////////////////////////////////
		//! \name Operador binario de la resta
		ed::Polinomio & operator-(ed::Polinomio const &p1, ed::Polinomio const &p2);
		ed::Polinomio & operator-(ed::Polinomio const &p, Monomio const &m);
		ed::Polinomio & operator-(Monomio const &m, ed::Polinomio const &p);
		ed::Polinomio & operator-(ed::Polinomio const &p, double const &x);
		ed::Polinomio & operator-(double const &x, ed::Polinomio const &p);

		///////////////////////////////////////////////////////////////////////////
		//! \name Operadores binarios de la multiplicación
		ed::Polinomio & operator*(ed::Polinomio const &p1, ed::Polinomio const &p2);
		ed::Polinomio & operator*(ed::Polinomio const &p, Monomio const &m);
		ed::Polinomio & operator*(Monomio const &m, ed::Polinomio const &p);
		ed::Polinomio & operator*(ed::Polinomio const &p, double const &x);
		ed::Polinomio & operator*(double const &x, ed::Polinomio const &p);

		///////////////////////////////////////////////////////////////////////////

		//! \name Operadores binarios de la división
		ed::Polinomio & operator/(ed::Polinomio const &p1, ed::Polinomio const &p2);
		ed::Polinomio & operator/(ed::Polinomio const &p, Monomio const &m);
		ed::Polinomio & operator/(Monomio const &m, ed::Polinomio const &p);
		ed::Polinomio & operator/(ed::Polinomio const &p, double const &x);
		ed::Polinomio & operator/(double const &x, ed::Polinomio const &p);

	/////////////////////////////////////////////////////////////////////////////

   //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    ostream &operator<<(ostream &stream, ed::Polinomio const &p);

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, ed::Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
