#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, -1), aux(nums.size(), 0);
        int Nsum = 0, Arrsum = 0, dup = -1;
        
        for(int i = 0; i < nums.size(); ++i){
            Nsum += i + 1;
            aux[nums[i]-1]++;
            if(aux[nums[i]-1] >= 2) ans[0] = nums[i];
            if(aux[nums[i]-1] < 2) Arrsum += nums[i];
        }
        
        //for(auto &a: aux) cout << " El: " << a;
        
        //cout << "\n" << Nsum << " " << Arrsum;
        ans[1] = Nsum - Arrsum;
        return ans;
    }
};