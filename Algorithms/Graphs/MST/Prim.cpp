#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvp;


#define fi first
#define sec second
#define pq(x) priority_queue<x, vector<x>, greater<x>>
#define pb push_back
#define mp make_pair

int NODES, INF;

bool comp(pii a, pii b) { 
    return a.fi < b.fi; 
}

vpi prim(vvp &graph){
    pq(pii) pq;

    int src = 0;
    vector<int> key(NODES, INF);
    vector<bool> inMST(NODES, false);
    vpi tree(NODES, mp(-1,-1));

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()){
        int curr = pq.top().second;
        pq.pop();

        if(inMST[curr]) continue;
        inMST[curr] = true; 

        for (int i = 0; i < graph[curr].size(); ++i){
            int next = graph[curr][i].first;
            int weight = graph[curr][i].second;


            if (!inMST[next] && tree[next].sec > weight){
                tree[next].sec = weight;
                pq.push(make_pair(tree[next].sec, next));
            }
        }
    }

    return tree;
}