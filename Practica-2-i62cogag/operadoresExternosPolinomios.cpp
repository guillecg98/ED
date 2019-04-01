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
	ed::Polinomio *nuevo = new ed::Polinomio(p);

	#ifndef NDEBUG
			assert( p == *nuevo );
	#endif

	return *nuevo;
}


ed::Polinomio & operator-(ed::Polinomio const & p)
{
	ed::Polinomio *nuevo = new ed::Polinomio();

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(-p.obtieneMonomio(i));
	}

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}

	#ifndef NDEBUG
		assert( p != *nuevo );
	#endif

	return *nuevo;
}

//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio;

	for(int i = 0; i < p1.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p1.obtieneMonomio(i));
	}

	for(int j = 0; j < p2.getNumeroMonomios(); j++)
	{
		nuevo->addMonomio(p2.obtieneMonomio(j));
	}

	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator+(ed::Polinomio const &p, Monomio const &m)
{
	ed::Polinomio *nuevo = new ed::Polinomio;

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i));
	}

	nuevo->addMonomio(m);
	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator+(Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio;

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i));
	}

	nuevo->addMonomio(m);
	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator+(ed::Polinomio const &p, double const &x)
{
	ed::Polinomio *nuevo = new ed::Polinomio;
	Monomio m = x;

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i));
	}

	nuevo->addMonomio(m);
	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator+(double const &x, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio;
	Monomio m = x;

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i));
	}

	nuevo->addMonomio(m);
	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

	////////////
	// Resta
ed::Polinomio & operator-(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio;

	for(int i = 0; i < p1.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p1.obtieneMonomio(i));
	}

	for(int j = 0; j < p2.getNumeroMonomios(); j++)
	{
		nuevo->addMonomio(-p2.obtieneMonomio(j));
	}

	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator-(ed::Polinomio const &p, Monomio const &m)
{
	ed::Polinomio *nuevo = new ed::Polinomio;

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i));
	}

	nuevo->addMonomio(-m);
	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator-(Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio;
	nuevo->addMonomio(m);

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(-p.obtieneMonomio(i));
	}

	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator-(ed::Polinomio const &p, double const &x)
{
	ed::Polinomio *nuevo = new ed::Polinomio;
	Monomio m = x;

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i));
	}

	nuevo->addMonomio(-m);
	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator-(double const &x, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio;
	Monomio m = x;
	nuevo->addMonomio(m);

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(-p.obtieneMonomio(i));
	}

	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}


	//////////////////
	// Multiplicación
ed::Polinomio & operator*(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio();

	for(int i = 0; i < p1.getNumeroMonomios(); i++)
	{
		for(int j = 0; j < p2.getNumeroMonomios(); j++)
		{
			nuevo->addMonomio(p1.obtieneMonomio(i) * p2.obtieneMonomio(j));
		}
	}
	nuevo->ordenaPolinomio();

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator*(ed::Polinomio const &p, Monomio const &m)
{
	ed::Polinomio *nuevo = new ed::Polinomio();

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i) * m);
	}

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator*(Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio();

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(m * p.obtieneMonomio(i));
	}

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator*(ed::Polinomio const &p, double const &x)
{
	ed::Polinomio *nuevo = new ed::Polinomio();

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(p.obtieneMonomio(i) * x);
	}

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator*(double const &x, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio();

	for(int i = 0; i < p.getNumeroMonomios(); i++)
	{
		nuevo->addMonomio(x * p.obtieneMonomio(i));
	}

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

	////////////
	// División
ed::Polinomio & operator/(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	#ifndef NDEBUG
		assert( p1.getGrado() >= p2.getGrado() );
		assert( p2.esNulo() == false );
	#endif

	ed::Polinomio *nuevo = new ed::Polinomio(p1);

	*nuevo/=p2;

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator/(ed::Polinomio const &p, Monomio const &m)
{
	#ifndef NDEBUG
		assert( m.getGrado() <= p.getGrado() );
	#endif

	ed::Polinomio *nuevo = new ed::Polinomio(p);

	if(m.getGrado() <= nuevo->getGrado())
	{
		*nuevo/=m;
	}

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator/(Monomio const &m, ed::Polinomio const &p)
{
	#ifndef NDEBUG
		assert( p.getGrado() <= m.getGrado() );
	#endif

	ed::Polinomio *nuevo = new ed::Polinomio(p);

	if(m.getGrado() <= nuevo->getGrado())
	{
		*nuevo/=m;
	}
	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator/(ed::Polinomio const &p, double const &x)
{
	#ifndef NDEBUG
		assert( std::abs((x-0.0) > COTA_ERROR) );
	#endif

	ed::Polinomio *nuevo = new ed::Polinomio(p);

	*nuevo/=x;
	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

ed::Polinomio & operator/(double const &x, ed::Polinomio const &p)
{
	#ifndef NDEBUG
		assert( p.getGrado() == 0 );
		assert( p.obtieneMonomio(0).getCoeficiente() != 0.0 );
	#endif

	ed::Polinomio *nuevo = new ed::Polinomio(p);

	*nuevo/=x;

	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < nuevo->getNumeroMonomios(); j++)
	{
		if( (nuevo->obtieneMonomio(j).getCoeficiente() == 0.0) && (nuevo->obtieneMonomio(j).getGrado() == 0))
		{
			nuevo->remove(j);
		}
	}
	return *nuevo;
}

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

	if(p.isOrdered() == false)
	{
		p.ordenaPolinomio();
	}
	//ahora tenemos que borrar aquellas posiciones que sean 0.0x^0 creadas por el constructor
	for(int j = 0; j < p.getNumeroMonomios(); j++)
	{
		if( (p.obtieneMonomio(j).getCoeficiente() == 0.0) && (p.obtieneMonomio(j).getGrado() == 0))
		{
			p.remove(j);
		}
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
