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
				// TODO
				this->setInfo(info);

				#ifndef NDEBUG
					assert( this->isHoja() == true );
				#endif
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				// TODO

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
				// TODO
				return this->_info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				// TODO
				return this->_izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				// TODO
				return this->_derecho;
			}

			bool esHoja() const
			{
				bool valor = false;
				// TODO
				if((this->getDerecho() == NULL) && (this->getIzquierdo() == NULL))
				{
					valor = true;
				}

				return valor;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				operador.aplicar(this->getInfo());
				if(this->getIzquierdo() != NULL)
				{
					operador.aplicar(this->getIzquierdo()->getInfo());
					this->recorridoPreOrden(operador);
				}
				if(this->getDerecho() != NULL)
				{
					operador.aplicar(this->getDerecho()->getInfo());
					this->recorridoPreOrden(operador);
				}
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				if(this->getIzquierdo() != NULL)
				{
					operador.aplicar(this->getIzquierdo()->getInfo());
					this->recorridoPreOrden(operador);
				}
				if(this->getDerecho() != NULL)
				{
					operador.aplicar(this->getDerecho()->getInfo());
					this->recorridoPreOrden(operador);
				}
				operador.aplicar(this->getInfo());
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				// TODO
				if(this->getIzquierdo() != NULL)
				{
					operador.aplicar(this->getIzquierdo()->getInfo());
					this->recorridoInOrden(operador);
				}
				operador.aplicar(this->getInfo());
				if(this->getDerecho() != NULL)
				{
					operador.aplicar(this->getDerecho()->getInfo());
					this->recorridoPreOrden(operador);
				}
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				this->_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				this->_izquierdo = n.getIzquierdo();
			}

			void setDerecho(NodoArbolBinario *n)
			{
				this->_derecho = n.getDerecho();
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				// TODO
				if((this->getInfo() != n.getInfo()) || (this->getDerecho() != n.getDerecho()) || (this->getIzquierdo() != n.getIzquierdo()))
				{
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
			*this = a;
			#ifndef NDEBUG
				assert( this->_raiz == a._raiz );
				assert( this->_raiz->getDerecho() == a._raiz->getDerecho() );
				assert( this->_raiz->getIzquierdo() == a._raiz->getIzquierdo() );
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
			// TODO
		}

		bool insertar(const G &x)
		{
			// TODO
			return false;
		}

		void borrarArbol()
		{
			// TODO
		}

		bool borrar()
		{
			// TODO
			return false;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		bool buscar(const G& x) const
		{
			// TODO
			return false;
		}

		bool estaVacio() const
		{
			bool valor = false;

			if(this->_raiz == NULL)
			{
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
			// TODO
			#ifndef NDEBUG
				assert( this->estaVacio() == false );
			#endif
			bool valor = false;

			if((this->_actual->getDerecho() != NULL) || (this->_actual->getIzquierdo() != NULL))
			{
				valor = true;
			}

			return valor;
		}

		G actual() const
		{
			// TODO
			#ifndef NDEBUG
				assert( this->existeActual() == true );
			#endif

			return this->_actual->getInfo();
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
