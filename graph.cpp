#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices) {

    //inicializando a variavel número de vertices
    this->num_vertices = num_vertices;

    //Determinando o tamanho do grafo com base no numero de vertices
    grafo.resize(num_vertices*2);
}

void Graph::adicionarAresta(int vertice1, int vertice2, int peso){
    //Transforma os indices dos vertices em par e impar
    int vertice1_par = vertice1*2;
    int vertice2_par = vertice2*2;
    int vertice1_impar = vertice1*2+1;
    int vertice2_impar = vertice2*2+1;

    //Criando o grafo G1 a partir dos vertices e peso de G    
    //Adiciona aresta nos dois sentidos, para garantir que o grafo seja não direcionado
    grafo[vertice1_par].push_back({ vertice2_impar, peso });
    grafo[vertice1_impar].push_back({ vertice2_par, peso });
    grafo[vertice2_par].push_back({ vertice1_impar, peso });
    grafo[vertice2_impar].push_back({ vertice1_par, peso });
}

void Graph::dijkstra(int vertice_origem, int vertice_destino){
    priority_queue<par_vertice_distancia> fila_prioridade;
    distancia = vector<int>(num_vertices*2, INF);   //Atualiza todas as distancias como infinito

    //Transforma o vertice de origem e destino em par
    int index_vertice_origem_par = 2*vertice_origem;
    int index_vertice_destino_par = 2*vertice_destino;

    distancia[index_vertice_origem_par] = 0;

    //Insere o vertice inicial com distancia 0
    fila_prioridade.push({index_vertice_origem_par,0});

    while(!fila_prioridade.empty()){
        int vertice_atual = fila_prioridade.top().vertice;   //vertice com a menor distancia
        int w = -fila_prioridade.top().dist;
        fila_prioridade.pop();

        //Se a distância atual já foi atualizada, então não precisamos processar esse vizinho novamente
        if(w!=distancia[vertice_atual])
            continue;

        // Percorrer as arestas do vértice atual
        for(auto aresta : grafo[vertice_atual]){
            int vertice_vizinho = aresta.vertice;    //vertice adjacente
            int dist = aresta.dist;           //distancia entre os vértices

                //Se encontrarmos um caminho mais curto
                if(distancia[vertice_vizinho]>distancia[vertice_atual]+dist){
                    distancia[vertice_vizinho] = distancia[vertice_atual] + dist;   //Atualiza distancia com o caminho mais curto
                    fila_prioridade.push({vertice_vizinho,-distancia[vertice_vizinho]});
            }
        }
    }
    //Se a distancia minima encontrada não for infinito, quer dizer que existe um caminho 
    if(distancia[index_vertice_destino_par]!=INF)
        cout << distancia[index_vertice_destino_par] << endl;
    //Senão, quer dizer que não existe caminho e da como saida -1
    else
        cout << -1 << endl;
}