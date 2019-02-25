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
		bool valorDevuelto = false;

		if( (m1.getGrado() == m2.getGrado()) && (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR) )
		{
			valorDevuelto = true;
		}
		#ifndef NDEBUG
			assert( valorDevuelto == ((m1.getGrado() == m2.getGrado()) and (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR) and (valorDevuelto == true)) );
		#endif

		return valorDevuelto;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD
	bool operator==(ed::Monomio const &m1, double const &x)
	{
		bool valorDevuelto = false;

		if( (m1.getGrado() == 0) && (std::abs(m1.getCoeficiente() - x) < COTA_ERROR) )
		{
			valorDevuelto = true;
		}

		#ifndef NDEBUG
			assert( valorDevuelto == ((m1.getGrado() == 0) and (std::abs(m1.getCoeficiente() - x) < COTA_ERROR) and (valorDevuelto == true)) );
		#endif

		return valorDevuelto;
	}

	bool operator==(double const &x, ed::Monomio const &m1)
	{
		bool valorDevuelto = false;

		if( (m1.getGrado() == 0) && (std::abs(m1.getCoeficiente() - x) < COTA_ERROR) )
		{
			valorDevuelto = true;
		}

		#ifndef NDEBUG
			assert( valorDevuelto == ((m1.getGrado() == 0) and (std::abs(m1.getCoeficiente() - x) < COTA_ERROR) and (valorDevuelto == true)) );
		#endif

		return valorDevuelto;
	}
	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool valorDevuelto = false;

		if( (m1.getGrado() != m2.getGrado()) || (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR) )
		{
			valorDevuelto = true;
		}

		#ifndef NDEBUG
			assert( valorDevuelto == ((m1.getGrado() != m2.getGrado()) || (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR) || (valorDevuelto == true)) );
		#endif

		return valorDevuelto;
	}

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD
	bool operator!=(double const &x, ed::Monomio const &m1)
	{
		bool valorDevuelto = false;

		if( (m1.getGrado() != 0) || (std::abs(m1.getCoeficiente() - x) > COTA_ERROR) )
		{
		 	valorDevuelto = true;
		}

		#ifndef NDEBUG
			assert( valorDevuelto == ((m1.getGrado() != 0) || (std::abs(m1.getCoeficiente() - x) > COTA_ERROR) || (valorDevuelto == true)) );
		#endif

		return valorDevuelto;
	}

	bool operator!=(ed::Monomio const &m1, double const &x)
	{
		bool valorDevuelto = false;

		if( (m1.getGrado() != 0) || (std::abs(m1.getCoeficiente() - x) > COTA_ERROR) )
		{
		 	valorDevuelto = true;
		}

		#ifndef NDEBUG
			assert( valorDevuelto == ((m1.getGrado() != 0) || (std::abs(m1.getCoeficiente() - x) > COTA_ERROR) || (valorDevuelto == true)) );
		#endif

		return valorDevuelto;
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
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() + m2.getCoeficiente())) < COTA_ERROR );
			assert( (nuevo->getGrado() == m1.getGrado()) and (nuevo->getGrado() == m2.getGrado()) );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert( m1.getGrado() == m2.getGrado() );
		#endif

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() - m2.getCoeficiente())) < COTA_ERROR );
			assert( (nuevo->getGrado() == m1.getGrado()) and (nuevo->getGrado() == m2.getGrado()) );
		#endif
		return *nuevo;
}

	//////////////////
	// Multiplicación
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m1.getGrado() + m2.getGrado());
		nuevo->setCoeficiente(m1.getCoeficiente() * m2.getCoeficiente());

		#ifndef NDEBUG
			assert( nuevo->getGrado() == (m1.getGrado() + m2.getGrado()) );
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * m2.getCoeficiente())) < COTA_ERROR );
		#endif

		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m1, double const &x)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * x);
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * x)) < COTA_ERROR );
		#endif

		return *nuevo;
	}

	ed::Monomio & operator* (double const &x, ed::Monomio const &m1)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(x * m1.getCoeficiente());
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs(nuevo->getCoeficiente() - (x * m1.getCoeficiente())) < COTA_ERROR );
		#endif

		return *nuevo;
	}

	////////////
	// División
ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
{
	#ifndef NDEBUG
		assert( m1.getGrado() >= m2.getGrado() );
		assert( m2.getCoeficiente() != 0.0 );
	#endif

	ed::Monomio *nuevo = new ed::Monomio();

	nuevo->setCoeficiente(m1.getCoeficiente()/m2.getCoeficiente());
	nuevo->setGrado(m1.getGrado()-m2.getGrado());

	#ifndef NDEBUG
		assert( nuevo->getGrado() == (m1.getGrado() - m2.getGrado()) );
		assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / m2.getCoeficiente())) < COTA_ERROR );
	#endif

	return *nuevo;
}

ed::Monomio & operator/ (ed::Monomio const &m1, double const &x)
{
	#ifndef NDEBUG
		assert( x != 0.0 );
	#endif

	ed::Monomio *nuevo = new ed::Monomio();

	nuevo->setCoeficiente(m1.getCoeficiente()/x);
	nuevo->setGrado(m1.getGrado());

	#ifndef NDEBUG
		assert( nuevo->getGrado() == m1.getGrado() );
		assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente()/x)) < COTA_ERROR );
	#endif

	return *nuevo;
}

ed::Monomio & operator/ (double const &x, ed::Monomio const &m1)
{
	#ifndef NDEBUG
		assert( m1.getGrado() == 0 );
		assert( m1.getCoeficiente() != 0.0 );
	#endif

	ed::Monomio *nuevo = new ed::Monomio();

	nuevo->setCoeficiente(x/m1.getCoeficiente());
	nuevo->setGrado(m1.getGrado());

	#ifndef NDEBUG
		assert( nuevo->getGrado() == 0 );
		assert( std::abs(nuevo->getCoeficiente() - (x / m1.getCoeficiente())) < COTA_ERROR );
	#endif

	return *nuevo;
}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		// COMPLETAR
		double coeficient;
		int grade;
		stream >> coeficient;
		stream >> grade;
		if( grade < 0 )
		{
			std::cout<<"No se debe introducir un grado menor que 0\n";
			exit (-1);
		}
		m.setCoeficiente(coeficient);
		m.setGrado(grade);
		// Se devuelve el flujo de salida
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		// COMPLETAR
		stream << m.getCoeficiente() << " " << m.getGrado();

		return stream;
	}

}  // namespace ed
