#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int maxi[n], mini[n];
        
        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        
        for(int i = 1; i < n; ++i){
            maxi[i] = max(nums[i], maxi[i - 1]); 
        }        
        
        
        for(int i = n-2; i >= 0; --i){

            mini[i] = min(nums[i], mini[i+1]);
        }
        
        int i = 0;
        while(i < n - 1){
            if (maxi[i] <= mini[i+1]) break;
            ++i;
        }
        
        /*
        [6,0,8,30,37,6,75,98,39,90,63,74,52,92,64]
        [6,6,8,30,37,37,75,98,98,98,98,98,98,98,98]
        [0,0,6,6,6,6,39,39,39,52,52,52,52,64]
        */
        
        if (i+1 == n) return 1;
        return i + 1;
    }
};