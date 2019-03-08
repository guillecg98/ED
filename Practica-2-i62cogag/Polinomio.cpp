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
		}
	}
}
/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR
