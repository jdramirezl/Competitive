/*
Dado un grafo con pesos, hallar el camino de i hasta j donde la arista m ́as
grande del camino sea lo mas peque posible.
Ejemplos: Que el peaje mas caro sea lo m ́as barato posible, que la autopista
mas larga sea lo mas corta posible
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int NODES, EDGES, INF;

int floyd(vvi &graph) {
    vvi distance(NODES, vi(NODES, INF));

    // Caso base
    for(int i=0; i<NODES; ++i){
        for(int j=0; j<NODES; ++j){
            if(i == j) distance[i][j] = 0;
            else if (graph[i][j]) distance[i][j] = graph[i][j];
            else distance[i][j] = INF;
        }
    }

    for(int k=0; k<NODES; ++k){
        for(int i=0; i<NODES; ++i){
            for(int j=0; j<NODES; ++j){
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
}