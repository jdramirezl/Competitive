#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>

void bfs(vvi &graph, vector<bool> &visited, int n_of_nodes){
    int curr_node = graph[0][0];
    queue<int> values;
    values.push(curr_node);
    visited[curr_node] = true;

    while(!values.empty()){
        int curr_node = values.front();
        values.pop();

        for(int i = 0; i < graph[curr_node].size(); ++i){
            int local_node = graph[curr_node][i];
            if(visited[local_node]) continue;
            //Do something
            visited[local_node] = true;
            values.push(local_node);
        }
    }
}