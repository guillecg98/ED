#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <iomanip>

#include <vector>

using namespace std;

namespace ed
{

template <class G_Nodo, class G_Lado>
class Grafo
{
private:
	G_Lado **_lados;

	G_Nodo *_nodos;

	int _numeroNodos;

	void init(int n)
	{
		this->_numeroNodos = n;
		this->_nodos = new G_Nodo[n]();
		this->_lados = new G_Lado *[n]();
		for (int i = 0; i < n; i++)
		{
			this->_lados[i] = new G_Lado[n];
		}
	}

public:
	// constructores
	Grafo()
	{
		this->_lados = NULL;
		this->_nodos = NULL;
	};

	Grafo(int n)
	{
		init(n);
	}
	Grafo(const Grafo &g)
	{
		init(g.getNumeroNodos());

		for (int i = 0; i < this->_numeroNodos; i++)
		{
			this->_nodos[i] = g.getNodos()[i];
			for (int j = 0; j < this->_numeroNodos; j++)
			{
				this->_lados[i][j] = g.getLado(i, j);
			}
		}
	}

	// destructor
	~Grafo()
	{
		borrarGrafo();
	};

	// funciones
	// TODO

	void borrarGrafo()
	{
		delete[] this->_nodos;
		for (int i = 0; i < this->_numeroNodos; i++)
		{
			delete[] this->_lados[i];
		}

		delete[] this->_lados;
	}

	Grafo operator=(const Grafo &g)
	{
		init(g.getNumeroNodos());

		for (int i = 0; i < this->_numeroNodos; i++)
		{
			this->_nodos[i] = g.getNodos()[i];
			for (int j = 0; j < this->_numeroNodos; j++)
			{
				this->_lados[i][j] = g.getLado(i, j);
			}
		}

		return *this;
	}

	void setNodos(std::vector<G_Nodo> vectorNodos)
	{
		copy(vectorNodos.begin(), vectorNodos.end(), this->_nodos);
	}

	void setLados(vector<G_Lado> vectorLados)
	{
		// for (int i = 0; i < this->_numeroNodos; i++)
		// {
		// 	std::copy(vectorLados[i * this->_numeroNodos].begin(), vectorLados[i * this->_numeroNodos].end() + this->_numeroNodos, this->_lados[i]);
		// }
		int n = 0;
		for (int i = 0; i < this->_numeroNodos; i++)
		{
			for (int j = 0; j < this->_numeroNodos; j++)
			{
				this->_lados[i][j] = vectorLados[i * this->_numeroNodos + j];

				n++;
			}
		}
	}

	inline G_Lado **getLados() const { return this->_lados; }
	inline G_Nodo *getNodos() const { return this->_nodos; }
	inline int getNumeroNodos() const { return this->_numeroNodos; }

	inline G_Lado getLado(int x, int y) const { return this->_lados[x][y]; }
	inline void setLado(int x, int y, G_Lado valor) { this->_lados[x][y] = valor; }

	void print()
	{
		for (int i = 0; i < this->_numeroNodos; i++)
		{
			cout << setw(15) << this->_nodos[i];
			for (int j = 0; j < this->_numeroNodos; j++)
			{
				cout << setw(8) << this->_lados[i][j];
			}
			cout << endl;
		}
	}

	G_Nodo getNodo(int pos) const
	{
		return _nodos[pos];
	}
};
} // namespace ed

#endif
