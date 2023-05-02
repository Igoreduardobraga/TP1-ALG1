#include <iostream>
#include "graph.hpp"
#include <limits.h>

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    // int N; //numero de cidades
    // int A; //numero de estradas conectando pares de cidades
    // int X1, X2, D;

    Graph grafo(5);

    grafo.adicionarAresta(0, 1, 4);
    grafo.adicionarAresta(0, 2, 8);
    grafo.adicionarAresta(1, 2, 2);
    grafo.adicionarAresta(1, 3, 5);
    grafo.adicionarAresta(2, 3, 5);
    grafo.adicionarAresta(2, 4, 9);
    grafo.adicionarAresta(3, 4, 4);

    // Executa o algoritmo de Dijkstra a partir do vértice 0.
    grafo.dijkstra(0);


    return 0;
}