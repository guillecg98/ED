#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"
#include "macros.hpp"

using namespace ed;
int menu();

int main()
{
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;

  // TODO
  int option;

  do{
    option = menu();

    std::cout << CLEAR_SCREEN;
		PLACE(3,1);

    switch (option)
    {
    case 0:
      	PLACE(3,1);
				std::cout << BIYELLOW;
				std::cout << "[0] Fin del programa" << std::endl << std::endl;
				std::cout << RESET;
			break;



    default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << option << std::endl;
				std::cout << RESET;
    }

    if (option !=0){
      std::cout << "Para mostrar el ";
      std::cout << BIGREEN ;
      std::cout << "menú, ";
      std::cout << RESET;
      std::cout << "pulse ";
      std::cout << INVERSE ;
      std::cout << "ENTER";
      std::cout << RESET;
      // Pausa
      std::cin.ignore();
      std::cout << CLEAR_SCREEN;
    }
  }while(option!=0);

  return 0;
}

int menu(){

   int opcion, posicion;
	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(posicion++,10);
	std::cout << BIBLUE;
	std::cout << "Programa principal | Opciones del menú";
	std::cout << RESET;

  posicion++;

	PLACE(posicion++,10);
	std::cout << "[1] Insertar Personas" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[2] Comprobar Persona" << std::endl;

  PLACE(posicion++,10);
	std::cout << "[3] Mostrar Arbol Pre-Orden" << std::endl;

  PLACE(posicion++,10);
	std::cout << "[4] Mostrar Arbol Post-Orden" << std::endl;

  PLACE(posicion++,10);
	std::cout << "[5] Mostrar Arbol In-Orden" << std::endl;

  PLACE(posicion++,10);
	std::cout << "[6] Borrar una Persona" << std::endl;

  PLACE(posicion++,10);
	std::cout << "[7] Borrar todas las Personas" << std::endl;

	posicion++;
	PLACE(posicion++,10);
	std::cout << BIRED;
	std::cout << "[0] Fin del programa " << std::endl;
	std::cout << RESET;

	posicion++;
	PLACE(posicion++,10);
	std::cout << BIYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;
	std::cin >> opcion;

   	// Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}
