// Max flow in O(v^2E)
// In bipartite graphs: O(sqrt(VE))

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<pii> vpi; // int int pair vec
typedef vector<vpi> vvp;

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

const int maxnodes = 5000;

int nodes = maxnodes, src, sink;
vi level(maxnodes), work(maxnodes);

struct Edge {
    int to, rev; // rev: reverse edge
    int flow, cap;
};

vector<Edge> graph[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, int cap){
    Edge a = {t, graph[t].size(), 0, cap};
    Edge b = {s, graph[s].size(), 0, cap};
    graph[s].push_back(a);
    graph[t].push_back(b);
}

bool dinic_bfs() {
    fill(all(level), -1);
    queue<int> q;
    q.push(src);
    level[src] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++) {
            Edge &e = graph[curr][i];
            int next = e.to;
            if (level[next] < 0 && e.flow < e.cap) {
                level[next] = level[curr] + 1;
                q.push(next);
            }
        }
    }
    return level[sink] >= 0;
}

int dinic_dfs(int curr, int flow) {
    if (curr == sink) return flow;

    for (int i = work[curr]; i < graph[curr].size(); i++) {
        Edge &e = graph[curr][i];
        if (e.cap <= e.flow) continue;
        int next = e.to;

        if (level[next] == level[curr] + 1) {
            int aug = dinic_dfs(next, min(flow, e.cap - e.flow));
            if (aug > 0) {
                e.flow += aug;
                graph[next][e.rev].flow -= aug;
                return aug;
            }
        }
    }
    return 0;
}

int maxFlow(int _src, int _dest) {
    src = _src;
    sink = _dest;
    int result = 0;
    while (dinic_bfs()) {
        fill(all(work), 0);
        while (int delta = dinic_dfs(src, INT_MAX)) result += delta;
    }
    return result;
}

int main() {
    int n = 3;
    nodes = n;

    // Create n*n matrix of capacities
    int capacity[][3] = { { 0, 3, 2 }, { 0, 0, 2 }, { 0, 0, 0 } };
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (capacity[i][j] != 0) addEdge(i, j, capacity[i][j]);
        }
    }
    cout << (4 == maxFlow(0, 2)) << endl;
}