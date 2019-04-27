#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{
				this->setInfo(info);
				this->setDerecho(NULL);
				this->setIzquierdo(NULL);

				#ifndef NDEBUG
					assert( this->esHoja() == true );
				#endif
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				*this = n;

				#ifndef NDEBUG
					assert( this->getInfo() == n.getInfo() );
					assert( this->getIzquierdo() == n.getIzquierdo() );
					assert( this->getDerecho() == n.getDerecho() );
				#endif
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				return this->_info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return this->_izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				return this->_derecho;
			}

			bool esHoja() const
			{
				bool valor = false;

				if((this->getIzquierdo() == NULL) && (this->getDerecho() == NULL)){
					valor = true;
				}

				return valor;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				operador.aplicar(this->getInfo());
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo()->recorridoPreOrden(operador);
				}
				if(this->getDerecho() != NULL){
					this->getDerecho()->recorridoPreOrden(operador);
				}
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo()->recorridoPreOrden(operador);
				}
				if(this->getDerecho() != NULL){
					this->getDerecho()->recorridoPreOrden(operador);
				}
				operador.aplicar(this->getInfo());
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo()->recorridoInOrden(operador);
				}
				operador.aplicar(this->getInfo());
				if(this->getDerecho() != NULL){
					this->getDerecho()->recorridoPreOrden(operador);
				}
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				this->_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				this->_izquierdo = n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				this->_derecho = n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				// TODO
				if((this->getInfo() != n.getInfo()) || (this->getDerecho() != n.getDerecho()) || (this->getIzquierdo() != n.getIzquierdo())){
					this->setInfo(n.getInfo());
					this->setDerecho(n.getDerecho());
					this->setIzquierdo(n.getIzquierdo());
				}
				#ifndef NDEBUG
					assert( this->getInfo() == n.getInfo() );
					assert( this->getDerecho() == n.getDerecho() );
					assert( this->getIzquierdo() == n.getIzquierdo() );
				#endif
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		ArbolBinarioOrdenadoEnlazado ()
		{
			// TODO
			this->_raiz = NULL;

			#ifndef NDEBUG
				assert( this->estaVacio() == true );
			#endif
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			// TODO
			this = a;
			#ifndef NDEBUG
				assert( this->_raiz == a._raiz );
				assert( this->_actual == a._actual );
				assert( this->_padre == a._padre );
			#endif
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			if(!this->estaVacio()){
				this->borrarArbol();
			}

			AlmacenarNodo<G> almacena;
			std::vector<G> myvec;

			a.recorridoPreOrden(almacena);

			myvec = almacena.vectorNodos();

			for(int i = 0; i< myvec.size(); i++){
				this->insertar(myvec[i]);
			}
			/*this->_raiz = a._raiz;
			this->_actual = a._actual;
			this->_padre = a._padre;*/
		}

		bool insertar(const G &x)
		{
			bool valor = false;
			int flag = 0;
			NodoArbolBinario *aux = this->getRaiz();
			NodoArbolBinario *nuevo(new NodoArbolBinario(x));

			if(this->estaVacio()){ //Si estamos insertando el primer elemento, la raiz apuntará a null antes de insertarlo
				this->_raiz = nuevo;
				valor = true;
				flag = 1;
			}
			while(flag == 0){
				if(aux->getInfo() > x){ //si x es menor que aux se comprueba el hijo izquierdo de aux
					if(aux->getIzquierdo() == NULL){ //si no exsite, se añade ahi el nuevo nodo
						aux->setIzquierdo(nuevo);
						valor = true;
						flag = 1;
					}else{
						aux = aux->getIzquierdo(); //si existe se sigue comprobando el arbol
					}
				}
				if(aux->getInfo() < x){ //si x es mayor que aux se comprueba el hijo derecho de aux
					if(aux->getDerecho() == NULL){//si no existe, se añade ahi el nuevo nodo
						aux->setDerecho(nuevo);
						valor = true;
						flag = 1;
					}else{
						aux = aux->getDerecho(); //si existe se sigue comprobando el arbol
					}
				}
				if(aux->getInfo() == x){
					flag = 1;
				}
			}
			return valor;
		}

		void borrarArbol()
		{
			#ifndef NDEBUG
				assert( not estaVacio() );
			#endif

			this->_raiz = NULL; //ponemos la raiz a null, así no existirá ningun elemento del arbol
			this->_actual = NULL;
			this->_padre = NULL;

			#ifndef NDEUBG
				assert( estaVacio() );
			#endif
		}

		bool borrar()
		{
			#ifndef NDEBUG
				assert( this->existeActual() == true );
			#endif

			NodoArbolBinario * anterior(this->_actual);
			this->_actual = NULL; //borramos el elemento que apunte actual
			NodoArbolBinario * nuevo(NULL);
			bool valor = false;

			if(anterior->getDerecho()){//si tiene hijo derecho
				nuevo = anterior->getDerecho();
				while(nuevo != NULL){//buscamos por todos los hijos izquierdos hasta llegar al que apunte a null
					if(nuevo->getIzquierdo() == NULL){
						this->_actual = nuevo; //si es el ultimo, este será el valor a reemplazar por el que hemos borrado
					}
					nuevo = nuevo->getIzquierdo();
				}
			}else if(anterior->getIzquierdo()){//si tiene hijo izquierdo
				nuevo = anterior->getIzquierdo();
				while(nuevo != NULL){//buscamos por todos los hijos derechos hasta llegar al que apunte a null
					if(nuevo->getDerecho() == NULL){
						this->_actual = nuevo; ////si es el ultimo, este será el valor a reemplazar por el que hemos borrado
					}
					nuevo = nuevo->getDerecho();
				}
			}else{//actual apunta a una hoja por lo que lo ponemos apuntando a la raiz
				this->_actual = this->_raiz;
			}

			#ifndef NDEBUG
				assert( buscar(anterior->getInfo()) == false );
			#endif

			return valor;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			this->_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			this->_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			this->_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x)
		{
			int flag = 0;
			bool valor = false;
			this->_actual = this->_raiz;
			NodoArbolBinario *anterior=NULL;
			this->_padre = anterior;

			while (flag == 0){//busqueda a traves del arbol binario empezando en la raiz mientras aux exista
				if(this->_actual->getInfo() > x){ // si x es menor que el nodo actual
					if(this->_actual->getIzquierdo() != NULL){//si existe izquierdo
						anterior = this->_actual;
						this->_actual = this->_actual->getIzquierdo();
					}
					flag = 1;
				}
				if (this->_actual->getInfo() < x){// si x es mayor que el nodo auxiliar
					if(this->_actual->getDerecho() != NULL){//si existe derecho
						anterior = this->_actual;
						this->_actual = this->_actual->getDerecho();
					}
					flag = 1;
				}
				if(this->_actual->getInfo() == x){ // si es igual que el nodo actual
					this->_padre = anterior;
					valor = true;
					flag = 1;
				}
			}

			#ifndef NDEBUG
				assert( (this->_actual->getInfo() == x) == valor );
			#endif

			return valor;
		}

		bool estaVacio() const
		{
			bool valor = false;

			if(this->_raiz == NULL){
				valor = true;
			}
			return valor;
		}

		G raiz() const
		{
			#ifndef NDEBUG
				assert( this->estaVacio() == false );
			#endif

			return this->_raiz->getInfo();
		}

		bool existeActual() const
		{
			#ifndef NDEBUG
				assert( this->estaVacio() == false );
			#endif
			bool valor = false;

			if((this->_actual->getDerecho() != NULL) || (this->_actual->getIzquierdo() != NULL)){
				valor = true;
			}

			return valor;
		}

		G actual() const
		{
			#ifndef NDEBUG
				assert( this->existeActual() == true );
			#endif

			return this->_actual->getInfo();
		}

		//funcion que devuelve el nodo raiz
		NodoArbolBinario *getRaiz() const
		{
			return this->_raiz;
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
