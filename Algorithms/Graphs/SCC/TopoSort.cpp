#include <bits/stdc++.h>

using namespace std;

#define vvi vector<vector<int>>

void DFS(vvi &graph, vector<int> &stack, vector<bool> &visited, int node){
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); ++i){
        int curr_node = graph[node][i];
        if (!visited[curr_node]) DFS(graph, stack, visited, curr_node);
    }
    
    stack.push_back(node);
}

void topo_sort(vvi &graph, vector<bool> &visited, vector<int> &stack){
    for (int i = 0; i < graph.size(); ++i){
        if (!visited[i]) DFS(graph, stack, visited, i);
    }
    reverse(stack.begin(), stack.end());
}

int main(){
    int n_of_nodes, n_of_edges, from, to;

    //Number of nodes and edges
    cin >> n_of_nodes >> n_of_edges;
    vvi graph(n_of_nodes, vector<int>()); 

    //Fill visited array
    vector<bool> visited(SIZE, false);

    //Fill graph
    for(int i=0; i<n_of_edges; ++i){
        cin >> from >> to;
        graph[from].push_back(to);
    }

    //TopoSort Stack
    vector<int> stack;

    topo_sort(graph, visited, stack);
}