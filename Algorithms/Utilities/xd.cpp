#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


#define pn pair<Node*, Node*>

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_set<int> vis;
        queue<pn> q;
        Node newnode;
        newnode.val = node -> val;
        q.push({node, &newnode});
        while(!q.empty()){
            Node *curr, *currcop;
            tie(curr, currcop) = q.front();
            q.pop();

            for(Node* next: curr -> neighbors){
                if(vis.count(next -> val)) continue;
                Node newnext;
                newnext.val = next->val;
                currcop -> neighbors.push_back(&newnext);
                q.push({next, &newnext});
                vis.insert(next -> val);
            }
        }

        return &newnode;
    }
};