#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = 0;
        for(const auto &a: nums) right += a;
        right -= nums[0];
        if (left == right) return 0;
        
        for(int i = 1; i < nums.size(); ++i){
            left += nums[i - 1];
            right -= nums[i];
            cout << left << " " << right <<endl;
            if (left == right) return i;
        }
        
        return -1;
    }
};