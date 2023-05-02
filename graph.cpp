#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices) {

    //inicializando a variavel número de vertices
    this->num_vertices = num_vertices;

    //Alocação dinâmica da matriz de adjacencia
    matriz_adjacencia = new vector<pair<int,int>>[num_vertices];
}

Graph::~Graph(){
    //Desalocação de memoria da matriz de adjacencia
    delete [] matriz_adjacencia;
}

void Graph::adicionarAresta(int u, int v, int w){
    matriz_adjacencia[u].push_back(make_pair(v,w));
    matriz_adjacencia[v].push_back(make_pair(u,w));
}

void Graph::dijkstra(int vertice_origem){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila_prioridade;
    distancia = vector<int>(num_vertices, INF);
    fila_prioridade.push(make_pair(0,vertice_origem));
    distancia[vertice_origem] = 0;

    while(!fila_prioridade.empty()){
        int u = fila_prioridade.top().second;
        fila_prioridade.pop();

        for(auto i = matriz_adjacencia[u].begin() ; i!=matriz_adjacencia[u].end() ; i++){
            int v = (*i).first;
            int largura = (*i).second;

            if(distancia[v] > distancia[u] + largura){
                distancia[v] = distancia[u] + largura;
                fila_prioridade.push(make_pair(distancia[v], v));
            }
        }
    }

    cout << "Distancias minimas de " << vertice_origem << ":\n";
        for (int i = 0; i < num_vertices; i++)
            cout << i << "\t" << distancia[i] << endl;
}