#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pop = 0;
        stack<int> res;
        for(int i = 0; i < pushed.size(); ++i){
            res.push(pushed[i]);
            while (pop < popped.size() && !res.empty() && res.top() == popped[pop]){
                pop++;
                res.pop();
            }
        }
        
        return res.empty();
    }
};