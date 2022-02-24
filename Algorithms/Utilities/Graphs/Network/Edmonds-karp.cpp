// O(VE^2) Vertices, Edges
/*
The matrix capacity stores the capacity for every pair of vertices. 
adj is the adjacency list of the undirected graph, since we have 
also to use the reversed of directed edges when we are looking for 
augmenting paths.

The function maxflow will return the value of the maximal flow. 
During the algorithm the matrix capacity will actually store the 
residual capacity of the network. The value of the flow in each 
edge will actually not be stored, but it is easy to extend the 
implementation - by using an additional matrix - to also store 
the flow and return it.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int src, int sink, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[src] = -2;
    queue<pair<int, int>> q;
    q.push({src, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == sink) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int src, int sink) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(src, sink, parent)) {
        flow += new_flow;
        int cur = sink;
        while (cur != src) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}