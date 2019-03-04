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

	/*!
		\brief Operador de igualdad: compara si un Monomio es igual a otro.
		\attention Se sobrecarga el operador de igualdad "=="
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param m2: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El valor devuelto es veradero si los grados y los coeficientes de ambos monomios son iguales
		\return verdadero, si los Monomios tienen las mismas componentes;
		\n falso, en caso contrario.
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\brief Operador de igualdad: compara si un Monomio es igual a un numero real.
		\attention Se sobrecarga el operador de igualdad "=="
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param x: variable de tipo double pasado como referencia constante
		\pre Ninguna
		\post El valor devuelto es veradero si el grado del monomio es igual a 0 y el coeficiente del monomio es igual al numero real
		\return verdadero, si el grado del monomio es igual a 0 y el coeficiente del monomio es igual al numero real
		\n falso, en caso contrario.
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	bool operator==(ed::Monomio const & m1, double const &x);

	/*!
		\brief Operador de igualdad: compara si un Monomio es igual a un numero real.
		\attention Se sobrecarga el operador de igualdad "=="
		\param x: variable de tipo double pasado como referencia constante
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El valor devuelto es veradero si el grado del monomio es igual a 0 y el coeficiente del monomio es igual al numero real
		\return verdadero, si el grado del monomio es igual a 0 y el coeficiente del monomio es igual al numero real
		\n falso, en caso contrario.
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	bool operator==(double const &x, ed::Monomio const & m1);


	//! \name Operadores de desigualdad

	/*!
		\brief Operador de desigualdad: compara si un Monomio es desigual a otro.
		\attention Se sobrecarga el operador de igualdad "!="
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param m2: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El valor devuelto es veradero si los grados o los coeficientes de ambos monomios son distintos
		\return verdadero, si los Monomios tienen diferentes componentes;
		\n falso, en caso contrario.
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\brief Operador de desigualdad: compara si un Monomio es distinto a un numero real.
		\attention Se sobrecarga el operador de igualdad "!="
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param x: variable de tipo double pasado como referencia constante
		\pre Ninguna
		\post El valor devuelto es veradero si los grados o los coeficientes de ambos monomios son distintos
		\return verdadero, si los Monomios tienen diferentes componentes;
		\n falso, en caso contrario.
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	bool operator!=(ed::Monomio const &m1, double const &x);

	/*!
		\brief Operador de desigualdad: compara si un Monomio es distinto a un numero real.
		\attention Se sobrecarga el operador de igualdad "!="
		\param x: variable de tipo double pasado como referencia constante
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El valor devuelto es veradero si los grados o los coeficientes de ambos monomios son distintos
		\return verdadero, si los Monomios tienen diferentes componentes;
		\n falso, en caso contrario.
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	bool operator!=(double const &x, ed::Monomio const &m1);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	/*!
		\brief Operador de prefijo: devuelve un Monomio con su signo real.
		\attention Se sobrecarga el operador unario prefijo "+"
		\param m: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El coeficiente del nuevo monomio es igual al coeficiente del monomio pasado por referencia
		\post El grado del nuevo monomio es igual al grado del monomio pasado por referencia
		\return nuevo monomio con el signo del monomio pasado por referencia constante
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator+(ed::Monomio const & m);

	/*!
		\brief Operador de prefijo: devuelve un Monomio con su signo opuesto.
		\attention Se sobrecarga el operador unario prefijo "-"
		\param m: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El coeficiente del nuevo monomio es igual al coeficiente opuesto del monomio pasado por referencia
		\post El grado del nuevo monomio es igual al grado del monomio pasado por referencia
		\return nuevo monomio con el signo opuesto del monomio pasado por referencia constante
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma

	/*!
		\brief Operador de suma: devuelve un Monomio que es la suma de otros dos Monomios.
		\attention Se sobrecarga el operador binario de suma "+"
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param m2: objeto de tipo Monomio pasado como referencia constante
		\pre Los grados de los monomios que se suman deben ser iguales
		\post El coeficiente del nuevo monomio es igual a la suma de los coeficientes de los monomios pasados por referencia constante
		\post El grado del nuevo monomio es igual al grado de los monomios pasados por referencia constante
		\return nuevo monomio igual a la suma de los dos monomios pasados por referencia constante
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta

	/*!
		\brief Operador de resta: devuelve un Monomio que es la resta de otros dos Monomios.
		\attention Se sobrecarga el operador binario de resta "-"
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param m2: objeto de tipo Monomio pasado como referencia constante
		\pre Los grados de los monomios que se restan deben ser iguales
		\post El coeficiente del nuevo monomio es igual a la diferencia de los coeficientes de los monomios pasados por referencia constante
		\post El grado del nuevo monomio es igual al grado de los monomios pasados por referencia constante
		\return nuevo monomio igual a la resta de los dos monomios pasados por referencia constante
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);



	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación

	/*!
		\brief Operador de producto: devuelve un Monomio que es el producto de otros dos Monomios.
		\attention Se sobrecarga el operador binario de producto "*"
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param m2: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El coeficiente del nuevo monomio es igual al producto de los coeficientes de los monomios pasados por referencia constante
		\post El grado del nuevo monomio es igual a la suma de los grados de los monomios pasados por referencia constante
		\return nuevo monomio igual al producto de los dos monomios pasados por referencia constante
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Operador de producto: devuelve un Monomio que es el producto de un monomio por un numero real.
		\attention Se sobrecarga el operador binario de producto "*"
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param x: variable de tipo double pasado como referencia constante
		\pre Ninguna
		\post El coeficiente del nuevo monomio es igual al producto del coeficiente del monomio por el numero real
		\post El grado del nuevo monomio es igual al grado del monomio pasado por referencia constante
		\return nuevo monomio igual al producto de un monomio por un real
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, double const &x);

	/*!
		\brief Operador de producto: devuelve un Monomio que es el producto de un numero real por un monomio.
		\attention Se sobrecarga el operador binario de producto "*"
		\param x: variable de tipo double pasado como referencia constante
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post El coeficiente del nuevo monomio es igual al producto del numero real por el coeficiente del monomio
		\post El grado del nuevo monomio es igual al grado del monomio pasado por referencia constante
		\return nuevo monomio igual al producto de un real por un monomio
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator* (double const &x, ed::Monomio const &m1);


	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división

	/*!
		\brief Operador de division: devuelve un Monomio que es la division de otros dos Monomios.
		\attention Se sobrecarga el operador binario de division "/"
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param m2: objeto de tipo Monomio pasado como referencia constante
		\pre El grado del Monomio divisor no puede ser menor que el grado del Monomio dividendo
		\pre El coeficiente del monomio divisor debe ser distinto de 0.0
		\post El coeficiente del nuevo monomio es igual al cociente de los coeficientes de los monomios pasados por referencia constante
		\post El grado del nuevo monomio es igual a la resta de los grados de los monomios pasados por referencia constante
		\return nuevo monomio igual al cociente de los dos monomios pasados por referencia constante
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Operador de division: devuelve un Monomio que es la division de un monomio entre un numero real.
		\attention Se sobrecarga el operador binario de producto "/"
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\param x: variable de tipo double pasado como referencia constante
		\pre El numero real debe ser distinto de 0.0
		\post El coeficiente del nuevo monomio es igual al cociente entre el coeficiente del monomio y el numero real
		\post El grado del nuevo monomio es igual al grado del monomio pasado por referencia constante
		\return nuevo monomio igual al cociente de un monomio entre un real
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator/ (ed::Monomio const &m1, double const &x);

	/*!
		\brief Operador de division: devuelve un Monomio que es la division de un numero real entre un monomio.
		\attention Se sobrecarga el operador binario de producto "/"
		\param x: variable de tipo double pasado como referencia constante
		\param m1: objeto de tipo Monomio pasado como referencia constante
		\pre El grado del monomio debe ser 0
		\pre El coeficiente del monomio debe ser distinto de 0.0
		\post El coeficiente del nuevo monomio es igual al cociente del numero real entre el coeficiente del monomio
		\post El grado del nuevo monomio es igual al grado del monomio pasado por referencia constante
		\return nuevo monomio igual al cociente de un real entre un monomio
		\note Se debe utilizar COTA_ERROR para controlar la precision de los numeros reales
		\sa ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	*/
	ed::Monomio & operator/ (double const &x, ed::Monomio const &m1);



	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	/*!
		\brief  Sobrecarga del operador de flujo de entrada o lectura ">>"
		\n Lee el coeficiente y el grado de un monomio separados por espacios
		\param stream: flujo de entrada
		\param m: objeto de tipo Monomio pasado como referencia constante
		\pre Ninguna
		\post Ninguna
	*/
	 istream &operator>>(istream &stream, ed::Monomio &m);

	 /*!
	 \brief  Sobrecarga del operador de flujo de salida o escritura "<<"
	 \n Escribe por pantalla el coeficiente y el grado de un Monomio separados por espacios
 	 \param  stream: flujo de salida
	 \param m: objeto de tipo Monomio pasado como referencia constante
	 \pre    Ninguna
	 \post   Ninguna
	 */
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);


}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
