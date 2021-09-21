#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num1, num2;
        vector<int> res;
        for(const auto &a: nums1){
            if (!num1[a]) num1[a] = 0;
            num1[a]++;
        }
        for(const auto &a: nums2){
            if (!num2[a]) num2[a] = 0;
            num2[a]++;
        }
        
        for(const auto &num: num1){
            if(num2[num.first] > 0){
                for(int i = 0; i < min(num2[num.first], num1[num.first]); ++i){
                    res.push_back(num.first);
                }
            }
        }
        
        return res;        
    }
};
