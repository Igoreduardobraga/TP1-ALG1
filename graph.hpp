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
        int distancia_minima;
        
        //Lista de adjacência
        vector<vector<pair<int,int>>> lista_adjacencia;
        vector<int> distancia;

    public:
        //Construtor do grafo
        Graph(int num_vertices);

        //Destrutor
        //~Graph();

        //Adiciona arestas ao grafo
        void adicionarAresta(int u, int v, int w);
        void dijkstra(int vertice_origem, int vertice_destino);
        void print_distancia_minima();
};

#endif // GRAPH_HPP