#include <bits/stdc++.h>

using namespace std;

#define MAXN 5 // highest value of node for a problem
#define vvi vector<vector<int>> 

void dfs(vvi &graph, vector<bool> &visited, int curr_node){
    cout << "Current Node: " << curr_node << endl;
    visited[curr_node] = true;

    for(int i=0; i<graph[curr_node].size(); ++i){
        int next = graph[curr_node][i];
        if(visited[curr_node]) continue;
        dfs(graph, visited, next);
    }
}


int main(){
    int n_of_nodes, n_of_edges, from, to;

    //Number of nodes and edges
    cin >> n_of_nodes >> n_of_edges;
    vvi graph(MAXN, vector<int>()); 

    //Fill visited array
    vector<bool> visited(MAXN, false);

    //Fill graph
    for(int i=0; i<n_of_edges; ++i){
        cin >> from >> to;
        graph[from].push_back(to);
    }

    for(int i=0; i<MAXN;++i) dfs(graph, visited, i);
}