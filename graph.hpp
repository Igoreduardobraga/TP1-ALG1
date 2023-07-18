#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct par_vertice_distancia{
    int vertice;
    int dist;

    bool operator<(const par_vertice_distancia& other) const {
        return dist < other.dist;
    }
};

class Graph {
    private:
        const int INF = 0x3f3f3f3f;
        int num_vertices;
        
        vector<vector<par_vertice_distancia>> grafo;    //grafo representado por meio de uma lista de adjacencia
        vector<int> distancia;      //armazena as distancias minimas ate cada vertice

    public:
        Graph(int num_vertices);    //Construtor do grafo
        void adicionarAresta(int u, int v, int w);  //Adiciona arestas ao grafo
        void dijkstra(int vertice_origem, int vertice_destino);
};

#endif // GRAPH_HPP