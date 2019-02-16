/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());

	#ifndef NDEBUG
		assert( std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR );
		assert( this->getGrado() == m.getGrado() );
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	// COMPLETAR
	this->setCoeficiente(x);
	this->setGrado(0);

	#ifndef NDEBUG
		assert( this->getGrado() == 0 );
		assert( std::abs(this->getCoeficiente() - x) < COTA_ERROR );
	#endif
	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	// COMPLETAR
	#ifndef NDEBUG
		assert( std::abs(m.getGrado()-this->getGrado()) < COTA_ERROR );
	#endif

	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();

	this->setCoeficiente(valorC + m.getCoeficiente());

	#ifndef NDEBUG
		assert( std::abs(this->getCoeficiente() - (valorC + m.getCoeficiente())) < COTA_ERROR );
		assert( std::abs(this->getGrado() - valorG) < COTA_ERROR );
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		assert( std::abs(m.getGrado()-this->getGrado()) < COTA_ERROR );
	#endif

	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();

	this->setCoeficiente(valorC - m.getCoeficiente());

	#ifndef NDEBUG
		assert( std::abs(this->getCoeficiente() - (valorC - m.getCoeficiente())) < COTA_ERROR );
		assert( std::abs(this->getGrado() - valorG) < COTA_ERROR );
	#endif

	return *this;
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();

	this->setGrado(valorG + m.getGrado());
	this->setCoeficiente(valorC * m.getCoeficiente());

	#ifndef NDEBUG
		assert( std::abs(this->getCoeficiente() - (valorC * m.getCoeficiente())) < COTA_ERROR );
		assert( std::abs(this->getGrado() - (valorG + m.getGrado())) < COTA_ERROR );
	#endif

	return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	#ifndef NDEUBUG
		assert( this->getGrado() > m.getGrado() );
		assert( m.getCoeficiente() != 0.0 );
	#endif

	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();

	this->setGrado(valorG - m.getGrado());
	this->setCoeficiente(valorC / m.getCoeficiente());

	#ifndef NDEUBUG
		assert( std::abs(this->getCoeficiente() - (valorC / m.getCoeficiente())) < COTA_ERROR );
		assert( std::abs(this->getGrado() - (valorG - m.getGrado())) < COTA_ERROR );
	#endif

	return *this;
}


ed::Monomio & ed::Monomio::operator*=(double const &x)
{
	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();

	this->setCoeficiente(valorC * x);

	#ifndef NDEUBUG
		assert( std::abs(this->getCoeficiente() - (valorC * x)) < COTA_ERROR );
		assert( std::abs(this->getGrado() - valorG) < COTA_ERROR );
	#endif

	return *this;
}

ed::Monomio & ed::Monomio::operator/=(double const &x) //DUDA: POR QUE SE DECLARAN ASI LAS FUNCIONES, Y LA DUDA DE DECLARAR CONTINUAMENTE VALORC Y VALORG
{
	#ifndef NDEBUG
		assert( x != 0.0 );
	#endif

	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();

	this->setCoeficiente(valorC / x);

	#ifndef NDEBUG
		assert( std::abs(this->getCoeficiente() - (valorC / x)) < COTA_ERROR );
		assert( std::abs(this->getGrado() - valorG) < COTA_ERROR );
	#endif

	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR
void ed::Monomio::leerMonomio()
{
	int valorG;
	double valorC;

	std::cout<<"Grado: ";
	std::cin>>valorG;
	std::cout<<"Coeficiente: ";
	std::cin>>valorC;

	this->setGrado(valorG);
	this->setCoeficiente(valorC);

	#ifndef NDEBUG
		assert( this->getGrado() >= 0 );
	#endif
}

void ed::Monomio::escribirMonomio()
{
	if(this->getCoeficiente() > 0)
	{
		switch (this->getGrado())
		{
			case 0:
				std::cout<<this->getCoeficiente()<<"\n";
			break;

			case 1:
				std::cout<<this->getCoeficiente()<<"x\n";
			break;

			default:
				std::cout<<this->getCoeficiente()<<"x^"<<this->getGrado()<<"\n";
		}
	}else {
		if(this->getCoeficiente() < 0)
		{
			switch (this->getGrado())
			{
				case 0:
					std::cout<<"-"<<this->getCoeficiente()<<"\n";
				break;

				case 1:
					std::cout<<"-"<<this->getCoeficiente()<<"x\n";
				break;

				default:
					std::cout<<"-"<<this->getCoeficiente()<<"x^"<<this->getGrado()<<"\n";
			}
		}else {
			std::cout<<"Error: El coeficiente es 0\n";
		}
	}
}
///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR
double ed::Monomio::calcularValor(double const &x)
{
	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();
	double potencia = std::pow(x,valorG);

	return valorC*potencia;
}
