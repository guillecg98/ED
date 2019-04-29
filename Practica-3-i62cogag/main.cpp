#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"
#include "macros.hpp"

using namespace ed;
int menu();
int generaRandom();

int main()
{
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<int> a;

  // TODO
  int option,nPersonas,cont;
	int num;
	EscribirNodo<int> escribe;
	AlmacenarNodo<int> almacena;

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

		case 1:
				std::cout<<"Inserte el numero de numeros\n";
				std::cin>>nPersonas;
				cont = 0;
				for(int i = 0; i<nPersonas; i++){
					std::cin>>num;
					if(a.insertar(num)){
						cont++;
					}
				}
				std::cout<<"Se han insertado "<<cont<<" numeros\n";
			break;

		case 2:
				if(!a.estaVacio()){
					std::cout<<"Introduce el numero a comprobar\n";
					std::cin>>num;
					if(a.buscar(num)){
						std::cout<<"El numero está en el arbol:\n"<<num;
					}else{
					std::cout<<"El numero que busca no se encuentra en el arbol\n";
					}
				}else{
					std::cout<<"El arbol está vacio\n";
				}
			break;

		case 3:
				if(a.estaVacio()){
					std::cout<<"No se pueden mostrar ya que el arbol está vacio\n";
				}else{
					a.recorridoPreOrden(almacena);//se almacenan los datos
					std::cout<<"Los datos pre orden son:\n";
					a.recorridoPreOrden(escribe);
				}
			break;

		case 4:
				if(a.estaVacio()){
					std::cout<<"No se pueden mostrar ya que el arbol está vacio\n";
				}else{
					a.recorridoPostOrden(almacena);//se almacenan los datos
					std::cout<<"Los datos post orden son:\n";
					a.recorridoPostOrden(escribe);
				}
			break;

		case 5:
				if(a.estaVacio()){
					std::cout<<"No se pueden mostrar ya que el arbol está vacio\n";
				}else{
					a.recorridoInOrden(almacena);//se almacenan los datos
					std::cout<<"Los datos in orden son:\n";
					a.recorridoInOrden(escribe);
				}
			break;

		case 6:
				if(!a.estaVacio()){
					std::cout<<"Introduce el numero a borrar\n";
					std::cin>>num;
					if(a.buscar(num)){
						a.borrar();
						std::cout<<"Se ha eliminado el numero indicado\n";
					}else{
						std::cout<<"No existe el numero que desea borrar\n";
					}
				}else{
					std::cout<<"El arbol está vacio\n";
				}
			break;

		case 7:
				if(a.estaVacio() == false){
					a.borrarArbol();
					std::cout<<"Se ha eliminado el arbol completo\n";
				}else{
					std::cout<<"El arbol ya está vacio\n";
				}
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

int generaRandom(){
	int valor = rand() % 100;
	return valor;
}
