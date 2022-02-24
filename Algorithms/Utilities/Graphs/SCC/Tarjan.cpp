#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
int NODES;

void findComponent(vvi &graph, vi &visited, vi &low, stack<int> &stk, vector<bool> &nodeinStack, int curr) {
    static int time = 0; // Same as using a int &time = 0 parameter
    visited[curr] = low[curr] = ++time; // Initially discovery time and low value is 1
    stk.push(curr);
    nodeinStack[curr] = true;    //flag as curr in the stack

    for(int i = 0; i<graph[curr].size(); i++) {
        int next = graph[curr][i];
        if(visited[next] == -1) {   // if next is not visited
            findComponent(graph, visited, low, stk, nodeinStack, next);
            low[curr] = min(low[curr], low[next]); // If in another iteration "next" gets in a group, curr must be in the group too
        } 
        else if(nodeinStack[next]){    //when v is in the stack, update low for curr
            low[curr] = min(low[curr], visited[next]);
        }
    }

    int poppedItem = 0;

    // If a nodes value is equal to its SCC value its because we completed a cycle and we need to remove the path
    if(low[curr] == visited[curr]) { 
        while(stk.top() != curr) {
            poppedItem = stk.top();
            cout << poppedItem << " ";
            nodeinStack[poppedItem] = false;    //mark as item is popped
            stk.pop();
        }
        poppedItem = stk.top();
        cout << poppedItem <<endl;
        nodeinStack[poppedItem] = false;
        stk.pop();
    }
}

void tarjan(vvi &graph) {
    /*
    Visited is either -1 (Not visited) or has a 
    value > 0 which represents the time of discovery
    or just a value assigned to it. Used for value of a
    group/SCC
    */
    vi visited(SIZE), low(SIZE);
    vector<bool> nodeinStack(SIZE);
    stack<int> stk;

    for(int i = 0; i<NODES; i++) {    
        visited[i] = low[i] = -1;
        nodeinStack[i] = false;
    }

    for(int i = 0; i<NODES; i++) { 
        if(visited[i] == -1) findComponent(graph, visited, low, stk, nodeinStack, i);
    }
}