#include <iostream>
#include "graph.hpp"

using namespace std;

int main() {
    int numero_cidades;
    int numero_estradas;
    int primeira_cidade, segunda_cidade, distancia;

    //Coleta a quantidade de vertices e arestas do grafo
    cin >> numero_cidades >> numero_estradas;

    //Cria o grafo com o numero de vertices igual ao numero de cidades
    Graph grafo(numero_cidades);

    //Percorre o grafo e coleta as arestas e pesos
    for(int i=0 ; i<numero_estradas ; i++){
        cin >> primeira_cidade >> segunda_cidade >> distancia;
        //Se a aresta tiver comprimento impar, ignore
        if(distancia % 2 != 0)
            continue;
        grafo.adicionarAresta(primeira_cidade-1,segunda_cidade-1,distancia);
    }

    grafo.dijkstra(0,numero_cidades-1);
}