#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30; 
typedef pair<int, int> pii; 
#define vvp vector<vector<pii>>

vector<int> dists(SIZE, INF), preds(SIZE, -1); // pred = predecesors for a given node


void dijkstra(int src, int n_of_nodes, vvp &graph){ // src = source node 
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    dists[src] = 0;
    pq.push(pii(0, src));
    
    while (!pq.empty()){
        int dist = pq.top().first; // dist != distS
        int curr = pq.top().second;

        pq.pop();
        if (dist > dists[curr]) continue;
        for (int i = 0; i < graph[curr].size(); ++i){
            int next = graph[curr][i].first;
            int next_w = graph[curr][i].second;
            if (dists[curr] + next_w < dists[next]){
                dists[next] = dists[curr] + next_w;
                preds[next] = curr;
                pq.push(pii(dists[next], next));
            }
        }
    }
}

// Si necesitamos devolver el camino
vector<int> find_path (int end){
    vector <int> path;
    int curr = end;
    
    while(curr != -1){
        path.push_back(curr);
        curr = preds[curr];
    }
    
    reverse(path.begin(), path.end());
    return path;
}
