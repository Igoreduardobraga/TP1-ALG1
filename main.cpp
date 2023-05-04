#include <iostream>
#include "graph.hpp"

using namespace std;

int main() {
    int numero_cidades;
    int numero_estradas;
    int X1, X2, distancia;

    cin >> numero_cidades >> numero_estradas;

    Graph grafo(numero_cidades);

    for(int i=0 ; i<numero_estradas ; i++){
        cin >> X1 >> X2 >> distancia;
        if(distancia%2 != 0)
            continue;
        grafo.adicionarAresta(X1-1,X2-1,distancia);
    }

    grafo.dijkstra(0,numero_cidades-1);

    // grafo.adicionarAresta(1, 2, 1);
    // grafo.adicionarAresta(2, 3, 2);
    // grafo.adicionarAresta(2, 5, 15);
    // grafo.adicionarAresta(3, 5, 1);
    // grafo.adicionarAresta(3, 4, 4);
    // grafo.adicionarAresta(5, 4, 3);
    // grafo.dijkstra(1);
}