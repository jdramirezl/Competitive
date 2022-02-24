#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<pii> vpi; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

void dfs_topo(vvi &graph, vector<int> &stack, vector<bool> &visited, int node){
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); ++i){
        int curr_node = graph[node][i];
        if (!visited[curr_node]) dfs_topo(graph, stack, visited, curr_node);
    }
    
    stack.pb(node);
}

void transpose(vvi &transposed_graph, vvi &original_graph){
    for (int i = 0; i < original_graph.size(); ++i){
        for (int j = 0; j < original_graph[i].size(); ++j){
            int curr_node = original_graph[i][j];
            transposed_graph[curr_node].pb(i);
        }
    }
}

void dfs(vvi &graph, vector<bool> &visited, int curr_node){
    if (visited[curr_node]) return;
    visited[curr_node] = true;

    for (int i = 0; i < graph[curr_node].size(); ++i){
        int next = graph[curr_node][i];
        dfs(graph, visited, next);
    }
}

void kosaraju(vvi &graph, vector<bool> &visited, int n_of_nodes){
    vector<int> ans;

    // Topo Sort
    for (int i = 0; i < graph.size(); ++i){
        if (!visited[i]) dfs_topo(graph, ans, visited, i);
    }

    reverse(all(ans));
    
    vvi transposed_graph(graph.size(), vi());

    transpose(transposed_graph, graph);
    
    for (int i = 0; i < visited.size(); i++) visited[i] = false; 
    bool pass = true;

    for (int i = 0; i < ans.size(); i++){
        int curr_node = ans[i];
        if (visited[curr_node]) continue;
        cout << "New Component: " << i << nl;
        dfs(transposed_graph, visited, curr_node);
    }
}