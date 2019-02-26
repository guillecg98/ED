/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

	// COMPLETAR
	double coeficiente;
	int grado;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

	/*!
		\brief Constructor que crea un Monomio a partir de su coeficiente y su grado
		\attention Funcion sobrecargada
		\note inline
		\param coeficiente: Coeficiente del monomio, valor por defecto = 0.0
		\param grado: Grado del monomio, valor por defecto = 0
		\pre El grado tiene que ser mayor o igual que 0
		\post El coeficiente nuevo tiene que ser igual que el antiguo
		\post El grado nuevo tiene que ser igual que el antiguo
		\sa setCoeficiente(), setGrado()
	*/
	inline Monomio(double coeficiente = 0.0, int grado = 0)
	{
		#ifndef NDEBUG
			assert( grado >= 0 );
		#endif

		this->setCoeficiente(coeficiente);
		this->setGrado(grado);

		#ifndef NDEBUG
			assert( std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR );
			assert( this->getGrado() == grado);
		#endif
	}

	/*!
	\brief Constructor de copia que crea un Monomio a partir de otro Monomio pasado como parametro
	\attention Funcion sobrecargada
	\note inline
	\param m: Monomio usado para proporcionar los datos al nuevo monomio
	\pre Ninguna
	\post El coeficiente del nuevo monomio tiene que ser igual al coeficiente del monomio pasado como parametro
	\post El grado del nuevo monomio tiene que ser igual al grado del monomio pasado como parametro
	\sa setCoeficiente(), setGrado()
	*/
	inline Monomio(const Monomio &m)
	{
		this->setCoeficiente(m.getCoeficiente());
		this->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert( std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR );
			assert( this->getGrado() == m.getGrado() );
		#endif
	}

	//! \name Observadores: funciones de consulta de la clase Monomio

	/*!
		\brief Funcion que devuelte el coeficiente de un Monomio
		\note Funcion inline
		\return Coeficiente del monomio en cuestion (tipo double)
		\pre Ninguna
		\post Ninguna
		\sa getCoeficiente()
	*/
	inline double getCoeficiente() const { return coeficiente; }
	/*!
		\brief Funcion que devuelte el grado de un Monomio
		\note Funcion inline
		\return Grado del monomio en cuestion (tipo int)
		\pre Ninguna
		\post Ninguna
		\sa getGrado()
	*/
	inline int getGrado() const { return grado; }


	//! \name Funciones de modificación de la clase Monomio

	/*!
		|brief Funcion que asigna un valor x al coeficiente del Monomio
		\note Funcion inline
		\param x: nuevo valor del coeficiente del monomio
		\pre Ninguna
		\post El nuevo coeficiente tiene que ser igual al valor recien asignado
		\note Se debe utilizar la COTA_ERROR para controlar la precision de los numeros reales
		\sa setCoeficiente()
	*/
	inline void setCoeficiente(double x)
	{
		coeficiente = x;

		#ifndef NDEBUG
			assert( std::abs(this->getCoeficiente() - x) < COTA_ERROR );
		#endif
	}

	/*!
		|brief Funcion que asigna un valor n al grado del Monomio
		\note Funcion inline
		\param n: nuevo valor del grado del monomio
		\pre El valor de n no puede ser menor que 0
		\post El nuevo grado tiene que ser igual al valor recien asignado
		\sa setGrado()
	*/
	inline void setGrado(int n)
	{
		#ifndef NDEBUG
			assert( n >= 0 );
		#endif

		grado = n;

		#ifndef NDEBUG
			assert( this->getGrado() == n );
		#endif
	}

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		/*!
		\brief Operador de asignacion: operador que "copia" un monomio en otro.
		\attention Se sobrecarga el operador de asignacion "="
		\warning Se requiere que las funciones de acceso getCoeficiente() y getGrado() tengan el modificador const
		\param m: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El coeficiente del nuevo monomio tiene que ser igual al coeficiente del monomio pasado como parametro
		\post El grado del nuevo monomio tiene que ser igual al grado del monomio pasado como parametro
		\note Se debe utilizar COTA_ERROR para controlar la precision de los nÃºmeros reales
		\sa getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
		*/
		Monomio & operator=(Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator+=(Monomio const &m);
		Monomio & operator-=(Monomio const &m);
		Monomio & operator*=(Monomio const &m);
		Monomio & operator/=(Monomio const &m);

		Monomio & operator*=(double const &x);
		Monomio & operator/=(double const &x);

		//FUNCION AÑADIDA
		Monomio & operator^=(int potencia);


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	// COMPLETAR
	void leerMonomio();
	void escribirMonomio();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	// COMPLETAR
	double calcularValor(double const &x);



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
