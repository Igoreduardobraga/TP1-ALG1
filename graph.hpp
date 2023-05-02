#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    private:
        const int INF = 0x3f3f3f3f;
        int num_vertices;
        
        //Matriz de adjacência
        vector<pair<int,int>> *matriz_adjacencia;
        vector<int> distancia;

    public:
        //Construtor do grafo
        Graph(int num_vertices);

        //Destrutor
        ~Graph();

        //Adiciona arestas ao grafo
        void adicionarAresta(int u, int v, int w);
        void dijkstra(int vertice_origem);
};

#endif // GRAPH_HPP