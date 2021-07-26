#include <bits/stdc++.h>
using namespace std;

#define MAXN 5 // highest value of node for a problem
#define vvi vector<vector<int>>

void print(vvi graph){
    cout << "\nstart! \n";
    for (int i = 0; i < graph.size(); ++i){
        cout << i << " ";
        for (int j = 0; j < graph[i].size(); ++j){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void topo_sort_util(vvi graph, vector<int> &stack, vector<bool> &visited, int node){
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); ++i){
        int curr_node = graph[node][i];
        if (visited[curr_node]) continue;
        topo_sort_util(graph, stack, visited, curr_node);
    }

    stack.push_back(node);
}

void topo_sort(vector<int> &sorted_graph, vvi graph, vector<bool> &visited, int n_of_nodes, int n_of_edges){
    for (int i = 0; i < MAXN; ++i){
        if (visited[i]) continue;
        topo_sort_util(graph, sorted_graph, visited, i);
    }
}

void transpose(vvi &transposed_graph, vvi original_graph){
    for (int i = 0; i < original_graph.size(); ++i){
        for (int j = 0; j < original_graph[i].size(); ++j){
            int curr_node = original_graph[i][j];
            transposed_graph[curr_node].push_back(i);
        }
    }
}

void dfs(vvi &graph, vector<bool> &visited, int curr_node){
    if (visited[curr_node]) return;
    visited[curr_node] = true;
    cout << "curr " << curr_node << " "; //PRINTING ELEMENT OF GROUP

    for (int i = 0; i < graph[curr_node].size(); ++i){
        int next = graph[curr_node][i];
        dfs(graph, visited, next);
    }
}

void kosaraju(vvi graph, vector<bool> visited, int n_of_nodes, int n_of_edges){
    vector<int> stack;
    topo_sort(stack, graph, visited, n_of_nodes, n_of_edges);
    reverse(stack.begin(), stack.end());

    vvi transposed_graph(graph.size(), vector<int>());
    transpose(transposed_graph, graph);

    for (int i = 0; i < visited.size(); i++) visited[i] = false; //Setting the visited vec as false for reusing

    for (int i = 0; i < stack.size(); i++){
        int curr_node = stack[i];
        if (visited[curr_node]) continue;
        dfs(transposed_graph, visited, curr_node);
        cout << endl; // New Line to show next SCC
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
    for (int i = 0; i < n_of_edges; ++i){
        cin >> from >> to;
        graph[from].push_back(to);
    }

    kosaraju(graph, visited, n_of_nodes, n_of_edges);
}