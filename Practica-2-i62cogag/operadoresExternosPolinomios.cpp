/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2)
{
	bool valor = true;

	for(int i = 0; i < p1.getNumeroMonomios(); i++)
	{
		if(p1.obtieneMonomio(i) != p2.obtieneMonomio(i))
		{
				valor = false;
		}
	}

	#ifndef NDEBUG
	for(int j = 0; j < p1.getNumeroMonomios(); j++)
	{
		if(p1.obtieneMonomio(j) != p2.obtieneMonomio(j))
		{
			assert( valor == false );
		}
	}
	#endif

	return valor;
}

bool operator==(ed::Polinomio const &p, Monomio const &m)
{
	bool valor = false;

	if((p.getNumeroMonomios() == 1) && (p.obtieneMonomio(0) == m))
	{
		valor = true;
	}

	#ifndef NDEBUG
	if((p.getNumeroMonomios() == 1) && (p.obtieneMonomio(0) == m))
	{
		assert( valor == true );
	}
	#endif

	return valor;
}

bool operator==(Monomio const &m, ed::Polinomio const &p)
{
	bool valor = false;

	if((p.getNumeroMonomios() == 1) && (m == p.obtieneMonomio(0)))
	{
		valor = true;
	}

	#ifndef NDEBUG
	if((p.getNumeroMonomios() == 1) && (m == p.obtieneMonomio(0)))
	{
		assert( valor == true );
	}
	#endif

	return valor;
}

bool operator==(ed::Polinomio const &p, double const &x)
{
	bool valor = false;

	if((p.getNumeroMonomios() == 1) && (p.obtieneMonomio(0) == x))
	{
		valor = true;
	}

	#ifndef NDEBUG
	if((p.getNumeroMonomios() == 1) && (p.obtieneMonomio(0) == x))
	{
		assert( valor == true );
	}
	#endif

	return valor;
}

bool operator==(double const &x, ed::Polinomio const &p)
{
	bool valor = false;

	if((p.getNumeroMonomios() == 1) && (x == p.obtieneMonomio(0)))
	{
		valor = true;
	}

	#ifndef NDEBUG
	if((p.getNumeroMonomios() == 1) && (x == p.obtieneMonomio(0)))
	{
		assert( valor == true );
	}
	#endif

	return valor;
}

////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad
bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2)
{
	bool valor = false;

	for(int i = 0; i < p1.getNumeroMonomios(); i++)
	{
		if(p1.obtieneMonomio(i) != p2.obtieneMonomio(i))
		{
				valor = true;
		}
	}

	#ifndef NDEBUG
	for(int j = 0; j < p1.getNumeroMonomios(); j++)
	{
		if(p1.obtieneMonomio(j) != p2.obtieneMonomio(j))
		{
			assert( valor == true );
		}
	}
	#endif

	return valor;
}

bool operator!=(ed::Polinomio const &p, Monomio const &m)
{
	bool valor = false;

	if( (p.getNumeroMonomios() > 1) || (p.obtieneMonomio(0) != m) )
	{
		valor = true;
	}

	#ifndef NDEBUG
		if( (p.getNumeroMonomios() > 1) || (p.obtieneMonomio(0) != m) )
		{
			assert( valor == true );
		}
	#endif

	return valor;
}

bool operator!=(Monomio const &m, ed::Polinomio const &p)
{
	bool valor = false;

	if( (p.getNumeroMonomios() > 1) || (m != p.obtieneMonomio(0)) )
	{
		valor = true;
	}

	#ifndef NDEBUG
		if( (p.getNumeroMonomios() > 1) || (m != p.obtieneMonomio(0)) )
		{
			assert( valor == true );
		}
	#endif

	return valor;
}

bool operator!=(ed::Polinomio const &p, double const &x)
{
	bool valor = false;

	if( (p.getNumeroMonomios() > 1) || (p.obtieneMonomio(0) != x) )
	{
		valor = true;
	}

	#ifndef NDEBUG
		if( (p.getNumeroMonomios() > 1) || (p.obtieneMonomio(0) != x) )
		{
			assert( valor == true );
		}
	#endif

	return valor;
}

bool operator!=(double const &x, ed::Polinomio const &p)
{
	bool valor = false;

	if( (p.getNumeroMonomios() > 1) || (x != p.obtieneMonomio(0)) )
	{
		valor = true;
	}

	#ifndef NDEBUG
		if( (p.getNumeroMonomios() > 1) || (x != p.obtieneMonomio(0)) )
		{
			assert( valor == true );
		}
	#endif

	return valor;
}



//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

// COMPLETAR
ed::Polinomio & operator+(ed::Polinomio const & p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio(p);

	// Se devuelve el resultado
	return *nuevo;
}


// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio;

	// Se devuelve el resultado
	return *nuevo;
}

	// COMPLETAR LOS OTROS OPERADORES DE SUMA

	////////////
	// Resta

	// COMPLETAR


	//////////////////
	// Multiplicación

	// COMPLETAR

	////////////
	// División

	// COMPLETAR


////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p)
{
	int tam;
	std::cout<<"Numero de monomios del Polinomio: ";
	std::cin>>tam;
	Monomio m;

	for(int i = 0; i < tam; i++)
	{
		stream >> m;
		p.addMonomio(m);
	}
  return stream;
}

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio const &p)
{
	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		if(i != 0)
		{
			std::cout<<" + ";
		}
		stream << p.obtieneMonomio(i);
	}
  return stream;
}


} // Fin del espacio de nombres ed
