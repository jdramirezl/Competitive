#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> sums;
        int sum, maxi = 0;
        
        for (int i = 0; i < wall.size(); ++i){
            sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j){
                sum += wall[i][j];
                if (!sums.count(sum)) sums[sum] = 0;
                sums[sum] += 1;
                maxi = max(maxi, sums[sum]);
            }
        }
        
        
        int ans = maxi - wall.size();
        if(!sums.empty()) return std::abs(ans);
        else return wall.size();
   
    }
};