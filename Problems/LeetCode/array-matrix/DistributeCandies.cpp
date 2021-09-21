#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size(), diff;
        unordered_set<int> types;
        
        for(const auto &el: candyType){
            if (types.count(el) == 0) diff++;
            types.insert(el);
        }
        
        n /= 2;
        return diff > n ? n : diff;
    }
};