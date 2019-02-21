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
		if( (m1.getGrado() == m2.getGrado()) and ((m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR) )
		{
			return true;
		}
		return false;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD
	bool operator==(ed::Monomio const &m1, double const &x)
	{
		if( (m1.getGrado() == 0) and ((m1.getCoeficiente() - x) < COTA_ERROR) )
		{
			return true;
		}
		return false;
	}

	bool operator==(double const &x, ed::Monomio const &m1)
	{
		if( (m1.getGrado() == 0) and ((m1.getCoeficiente() - x) < COTA_ERROR) )
		{
			return true;
		}
		return false;
	}
	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if( (m1.getGrado() != m2.getGrado()) || ((m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR) )
		{
			return true;
		}
		return false;
	}

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD
	bool operator!=(double const &x, ed::Monomio const &m1)
	{
		if( (m1.getGrado() != 0) || ((m1.getCoeficiente() - x) > COTA_ERROR) )
		{
			return true;
		}
		return false;
	}

	bool operator!=(ed::Monomio const &m1, double const &x)
	{
		if( (m1.getGrado() != 0) || ((m1.getCoeficiente() - x) > COTA_ERROR) )
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

		nuevo->setCoeficiente(m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert( std::abs(nuevo->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR );
			assert( nuevo->getGrado() == m.getGrado() );
		#endif
		// Se devuelve el resultado
		return *nuevo;
	}

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta
	ed::Monomio & operator-(ed::Monomio const & m)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(-m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert( std::abs(m.getCoeficiente() + nuevo->getCoeficiente()) < COTA_ERROR );
			assert( nuevo->getGrado() == m.getGrado() );
		#endif

		return *nuevo;
	}

	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// COMPLETAR Y MODIFICAR
		#ifndef NDEBUG
			assert( m1.getGrado() == m2.getGrado() );
		#endif
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());

		#ifndef NDEBUG
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() + m2.getCoeficiente())) < COTA_ERROR );
			//si se ha cumplido la precondicion no hace falta poner la postcondicion del grado :)
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta
ed::Monomio & operator- (ED::Monomio const &m1, ed::Monomio const &m2)
{
	#ifndef NDEBUG
		assert( m1.getGrado() == m2.getGrado() );
	#endif

	ed::Monomio *nuevo = new ed::Monomio();

	nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());

	#ifndef NDEBUG
		assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() - m2.getCoeficiente())) < COTA_ERROR );
		//si se ha cumplido la precondicion no hace falta poner la postcondicion del grado :)
	#endif

	return *nuevo;
}


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
