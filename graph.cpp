#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices) {

    //inicializando a variavel número de vertices
    this->num_vertices = num_vertices;

    //Alocação dinâmica da matriz de adjacencia
    lista_adjacencia.resize(num_vertices);
}

// Graph::~Graph(){
//     //Desalocação de memoria da matriz de adjacencia
//     delete lista_adjacencia;
// }

void Graph::adicionarAresta(int v, int u, int w){
    lista_adjacencia[v].push_back({u,w}); 
}

void Graph::dijkstra(int vertice_origem, int vertice_destino){
    priority_queue<pair<int,int>> fila_prioridade;
    distancia = vector<int>(num_vertices,INF);
    distancia[vertice_origem] = 0;

    fila_prioridade.push({0,vertice_origem});

    while(!fila_prioridade.empty()){
        int v = fila_prioridade.top().second;
        int w = -fila_prioridade.top().first;
        fila_prioridade.pop();

        //Ignora a atualização de u caso um caminho mais curto tenha sido encontrado
        if(w!=distancia[v])
            continue;

        for(auto vizinho : lista_adjacencia[v]){
            int u = vizinho.first;
            int dist = vizinho.second;
            if ((distancia[v] + dist) % 2 == 0) {
                if(distancia[u]>distancia[v]+dist){
                    distancia[u] = distancia[v] + dist;
                    fila_prioridade.push({-distancia[u],u});
                }
            }
        }
    }
    if(distancia[vertice_destino]!=INF)
        cout << distancia[vertice_destino] << endl;
    else
        cout << -1 << endl;
}