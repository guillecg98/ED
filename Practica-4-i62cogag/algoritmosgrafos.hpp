#ifndef __ALGORITMOSGRAFOS_H__
#define __ALGORITMOSGRAFOS_H__
#include <iostream>

#include "grafo.hpp"
using namespace ed;
using namespace std;

template <class G_Nodo, class G_Lado>
class AlgoritmosGrafos
{
private:
  G_Nodo **_recorridos;
  G_Lado **_distancias;
  Grafo<G_Nodo, G_Lado> _grafo;

public:
  AlgoritmosGrafos(const Grafo<G_Nodo, G_Lado> grafo)
  {
    _grafo = grafo;
    _distancias = new G_Lado *[_grafo.getNumeroNodos()];
    for (int i = 0; i < _grafo.getNumeroNodos(); i++)
    {
      _distancias[i] = new G_Lado[_grafo.getNumeroNodos()];
      for (int j = 0; j < _grafo.getNumeroNodos(); j++)
      {
        _distancias[i][j] = _grafo.getLado(i, j);
      }
    }

    _recorridos = new G_Nodo *[_grafo.getNumeroNodos()];
    for (int i = 0; i < _grafo.getNumeroNodos(); i++)
    {
      _recorridos[i] = new G_Nodo[_grafo.getNumeroNodos()];
      for (int j = 0; j < _grafo.getNumeroNodos(); j++)
      {
        _recorridos[i][j] = _grafo.getNodo(j);
      }
    }
  }

  void Floyd()
  {

    G_Nodo aux_nodo;
    for (int i = 0; i < _grafo.getNumeroNodos(); i++)
    {
      _grafo.setLado(i, i, 0);
    }
    // Realiza el algoritmo de Floys
    for (int k = 0; k < _grafo.getNumeroNodos(); k++)
      for (int i = 0; i < _grafo.getNumeroNodos(); i++)
        for (int j = 0; j < _grafo.getNumeroNodos(); j++)
        {
          int dt = _grafo.getLado(i, k) + _grafo.getLado(k, j);
          if (_grafo.getLado(i, j) > dt)
          {
            _grafo.setLado(i, j, dt);
            _recorridos[i][j] = _recorridos[i][k];
          }
        }
  }
  void imprimeMatrices()
  {

    // Imprime la matriz de distancias
    cout << endl;
    cout << endl;
    cout << "Matriz de distancias" << endl;
    _grafo.print();
    cout << endl;
    cout << "Matriz de recorridos" << endl;
    for (int i = 0; i < _grafo.getNumeroNodos(); i++)
    {
      cout << "[";
      for (int j = 0; j < _grafo.getNumeroNodos(); j++)
      {
        cout << _recorridos[i][j] << " ";
      }
      cout << "]" << endl;
    }
  }

  void imprimeCamino(string salida, string llegada)
  {
    int numSalida = 0;
    int numLlegada = 0;
    bool encontrado = false;
    int numPrimeraSalida = 0;
    string camino = salida;

    for (int i = 0; i < _grafo.getNumeroNodos(); i++)
    {
      if (salida == _grafo.getNodo(i))
      {
        numPrimeraSalida = i;
      }
      if (llegada == _grafo.getNodo(i))
      {
        numLlegada = i;
      }
    }

    while (!encontrado)
    {
      for (int i = 0; i < _grafo.getNumeroNodos(); i++)
      {
        if (salida == _grafo.getNodo(i))
        {
          numSalida = i;
        }
      }
      if (_recorridos[numSalida][numLlegada] == llegada)
      {
        encontrado = true;
      }

      camino = camino + "-" + _recorridos[numSalida][numLlegada];
      salida = _recorridos[numSalida][numLlegada];
    }
    cout << "Distancia : " << _grafo.getLado(numPrimeraSalida, numLlegada) << endl;
    cout << "Camino : " << camino << endl;
  }
};

#endif
