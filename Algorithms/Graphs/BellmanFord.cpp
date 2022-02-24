#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<pair<int, int>>>
#define INF INT_MAX
/*
If we want to check for negative cycles we run the algo for
NODES rounds, and if it reduces on the last round there is 
a negative cycle
*/

int NODES;
void bellman(int src, vvi &graph){
    vector<int> distance(NODES, INF);
    distance[src] = 0;

    for(int i = 0; i <= NODES - 1; ++i) {
        for(auto edge: graph[i]) {
            int curr = i, next, next_w;
            tie(next, next_w) = edge;
            distance[next] = min(distance[next], distance[curr] + next_w);
        }
    }
}