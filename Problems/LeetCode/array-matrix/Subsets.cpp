#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>  ans;
    void aux(vector<int>& nums, vector<int> &subset, int i){
        if (i == nums.size()) {ans.push_back(subset); return;}
        subset.push_back(nums[i]);
        aux(nums, subset, i + 1);
        subset.pop_back();
        aux(nums, subset, i + 1);
        
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        aux(nums, subset, 0);
        return ans;
    }
};