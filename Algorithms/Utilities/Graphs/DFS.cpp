#include <bits/stdc++.h>

using namespace std;

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