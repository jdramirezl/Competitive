#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int  arsum = 0;
        
        for (const auto &a: nums) arsum += a;
        return ((nums.size()*(nums.size()+1))/2) - arsum;
    }
};