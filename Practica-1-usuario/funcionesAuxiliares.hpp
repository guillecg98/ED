/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author Guillermo Cosano Galiot
  \date  27-02-2019
*/


#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

namespace ed
{
	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!
		\brief Esta funcion comprueba todos metodos relacionados directamente con un monomio.
		\param Ninguno
		\pre Ninguna
		\post Ninguna
	*/
	void testMonomio();


	/*!
		\brief Esta funcion comprueba todos metodos y operadores externos a la clase Monomio.
		\param Ninguno
		\pre Ninguna
		\post Ninguna
	*/
	void operadoresExternosMonomios();

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
