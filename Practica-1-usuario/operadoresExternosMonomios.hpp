/*!
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);
	bool operator==(ed::Monomio const & m1, double const &x);
	bool operator==(double const &x, ed::Monomio const & m1);


	//! \name Operadores de desigualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);
	bool operator!=(double const &x, ed::Monomio const &m1);
	bool operator!=(ed::Monomio const &m1, double const &x);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	ed::Monomio & operator+(ed::Monomio const & m);

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta
	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);



	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);
	ed::Monomio & operator* (ed::Monomio const &m1, double const &x);
	ed::Monomio & operator* (double const &x, ed::Monomio const &m1);


	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);
	ed::Monomio & operator/ (ed::Monomio const &m1, double const &x);
	ed::Monomio & operator/ (double const &x, ed::Monomio const &m1);



	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
