/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if( (m1.getGrado() == m2.getGrado()) and (m1.getCoeficiente() == m2.getCoeficiente()) )
		{
			return true;
		}
		return false;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD
	bool operator==(ed::Monomio const &m1, double const &x)
	{
		if( (m1.getGrado() == 0) and (m1.getCoeficiente() == x) )
		{
			return true;
		}
		return false;
	}

	bool operator==(double const &x, ed::Monomio const &m1)
	{
		if( (m1.getGrado() == 0) and (m1.getCoeficiente() == x) )
		{
			return true;
		}
		return false;
	}
	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if( (m1.getGrado() != m2.getGrado()) || (m1.getCoeficiente() != m2.getCoeficiente()) )
		{
			return true;
		}
		return false;
	}

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD
	bool operator!=(double const &x, ed::Monomio const &m1)
	{
		if( (m1.getGrado() != 0) || (m1.getCoeficiente() != x) )
		{
			return true;
		}
		return false;
	}

	bool operator!=(ed::Monomio const &m1, double const &x)
	{
		if( (m1.getGrado() != 0) || (m1.getCoeficiente() != x) )
		{
			return true;
		}
		return false;
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado
		return *nuevo;
	}

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta

	// COMPLETAR


	//////////////////
	// Multiplicación

	// COMPLETAR

	////////////
	// División

	// COMPLETAR


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		// COMPLETAR

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		// COMPLETAR

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
