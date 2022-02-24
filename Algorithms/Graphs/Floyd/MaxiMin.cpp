/*
Dado un grafo con pesos, hallar el camino de i hasta j donde la arista mas
peque la del camino sea lo m ́as grande posible.
Ejemplos: Que el trayecto menos seguro sea lo mas seguro posible, que la
autopista de menos carriles tenga la mayor cantidad de carriles.
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
            if(i == j) distance[i][j] = INF;
            else if (graph[i][j]) distance[i][j] = graph[i][j];
            else distance[i][j] = -INF;
        }
    }

    for(int k=0; k<NODES; ++k){
        for(int i=0; i<NODES; ++i){
            for(int j=0; j<NODES; ++j){
                distance[i][j] = max(distance[i][j], min(distance[i][k], distance[k][j]));
            }
        }
    }
}