#include <bits/stdc++.h>
using namespace std;


// Leader -> Node whose parent is itself
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

int main(){
    initialize(5);
    join(3,1);
    join(4,1);
    join(2,4);
}