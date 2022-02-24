#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;
#define all(v) v.begin(), v.end()


const int MAXN = 100005;
int p[MAXN];

void initialize(int n){
    for (int i = 0; i <= n; ++i) p[i] = i; 
}

int find(int u){
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

void join(int u, int v){
    int a = find(u);
    int b = find(v);
    if (a == b) return;
    p[a] = b;  
}

struct edge {
    int a, b, w;
};

bool sort_edges(edge x, edge y){
    return x.w < y.w; 
}

int NODES;
vector<vpi> kruskal(vector<vpi> &graph){
    vector<edge> edges;

    for(int i=0; i<graph.size(); ++i){
        for(int j=0; j<graph[0].size(); ++j){
            edges.push_back({i, graph[i][j].first, graph[i][j].second});
        }
    }

    sort(all(edges), sort_edges);

    vector<vpi> tree;
    initialize(NODES);

    for (auto e: edges){
        if(find(e.a) != find(e.b)){
            tree[e.a].push_back({e.b, e.w});
            join(e.a, e.b);
        }
    }

    return tree;
}

