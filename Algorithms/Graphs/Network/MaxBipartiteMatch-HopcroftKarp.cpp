/*
We create the matching set
We find an augmenting path:
    A path which alternates between matching and
    not matching edges and has free vertices
    (vertices that havent been matched) as 
    starting and ending points
When we have this path we change matching to not-maching edges and viceversa

O(sqrt(v)*e)
*/

#include <bits/stdc++.h>
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

#define vi vector<int>
#define vb vector<bool>

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges; // set1 and set2 sizes, n of edges
vi last(MAXN1), prevs(MAXM), head(MAXM), matching(MAXN2), dist(MAXN1), free_nodes(MAXN1);
vb used(MAXN1), visited(MAXN1);

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    /* 
    last[i]: saves the number of edges when node 'i' was inserted
    ex: 
    last = [0, 1]
    prevs = [-1, 0]
    means, for node 0, the graph was empty before it (-1 edges)
    for node 1 the prev is the last, so 0 edges before it was inserted
    */
    fill(all(last), -1); 
}

void addEdge(int u, int v) {
    /*
        head[]: saves for the ith edge what node its pointing to
    */
    head[edges] = v;
    prevs[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(all(last), -1);
    int total_free = 0;
    for (int curr = 0; curr < n1; ++curr) {
        // if a node is not used, means its free, save it
        if (!used[curr]) {
            free_nodes[total_free++] = curr;
            dist[curr] = 0;
        }
    }
    for (int i = 0; i < total_free; i++) {
        int curr_free = free_nodes[i];
        // gets the num of edges before curr_free
        // backtracks through prevs
        for (int e = last[curr_free]; e >= 0; e = prevs[e]) {
            int u2 = matching[head[e]]; // Gets the match for the curr node head[e]
            if (u2 != -1 && dist[u2] < 0) { // if there is a match and there is no distance (-1)
                dist[u2] = dist[curr_free] + 1;
                free_nodes[total_free++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    // relation: u1 -> v -> u2
    visited[u1] = true;
    for (int e = last[u1]; e >= 0; e = prevs[e]) {
        int v = head[e];
        int u2 = matching[v];
        // if there is no match for V or we havent visited the match
        // and the distance between u2 and u1 differs by 1
        // and dfs(u2)
        if (u2 < 0 || !visited[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    // No nodes are used, there are no pairs/matches
    fill(all(used), false);
    fill(all(matching), -1); // matching[i]: saves the match for node 'i'

    int total = 0;
    while (true) {
        bfs(); // Finds augmenting path
        fill(all(visited), false);

        // Number of new flows
        int flow = 0;
        for (int curr = 0; curr < n1; ++curr){
            if (!used[curr] && dfs(curr)) ++flow;
        }

        // if there aren't any new flows we return
        if (!flow) return total;
        else total += flow;
    }
}

int main() {
    init(2, 2);

    addEdge(0, 0);
    addEdge(0, 1);
    addEdge(1, 1);

    cout << (2 == maxMatching()) << endl;
}