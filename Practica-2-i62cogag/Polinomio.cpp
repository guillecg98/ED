/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

// Operadores de asignación

// COMPLETAR

void ed::Polinomio::ordenaPolinomio()
{
	#ifndef NDEBUG
		assert( this->esNulo() == false );
		assert( this->isOrdered() == false );
	#endif

	Monomio aux;

	//bucle para ordenar
	for( int i = 0; i < this->getNumeroMonomios()-1; i++)
	{
		if(this->vector[i].getGrado() < this->vector[i+1].getGrado())
		{
			aux.setGrado(this->vector[i].getGrado());
			this->vector[i].setGrado(this->vector[i+1].getGrado());
			this->vector[i+1].setGrado(aux.getGrado());
		}
	}

	//bucle que suma aquellos monomios con mismo grado
	for( int i = 0; i < this->getNumeroMonomios() -1; i++)
	{
		if(this->vector[i].getGrado() == this->vector[i+1].getGrado())
		{
			this->vector[i] += this->vector[i+1];
			this->vector.erase(this->vector.begin()+i+1);
		}
	}
}
/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	if(&p != this)
	{
		this->vector.clear();
		this->vector = p.vector;
	}
	// Se devuelve el objeto actual
	#ifndef NDEBUG
		assert( this == &p );
	#endif

	return *this;
}

ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	this->vector.clear();
	this->vector.push_back(m);

	#ifndef NDEBUG
		assert( this->vector.front() == m );
	#endif

	return *this;
}

ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	// COMPLETAR
	this->vector.clear();
	Monomio m;
	m = x;
	this->vector.push_back(m);
	// Se devuelve el objeto actual
	#ifndef NDEBUG
		assert( this->vector.front() == x );
	#endif

	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	for( int i = 0; i < p.getNumeroMonomios(); i++)
	{
		this->vector.push_back(p.vector[i]);
	}
	this->ordenaPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES
ed::Polinomio & ed::Polinomio::operator+=(Monomio const &m)
{
	this->vector.push_back(m);
	this->ordenaPolinomio();
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{
	Monomio m;
	m = x;
	this->vector.push_back(m);
	this->ordenaPolinomio();
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p)
{
	for( int i = 0; i < p.getNumeroMonomios(); i++)
	{
		this->vector.push_back(-p.vector[i]);
	}
	this->ordenaPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(Monomio const &m)
{
	this->vector.push_back(-m);
	this->ordenaPolinomio();
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{
	Monomio m;
	m = x;
	this->vector.push_back(-m);
	this->ordenaPolinomio();
	return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR
