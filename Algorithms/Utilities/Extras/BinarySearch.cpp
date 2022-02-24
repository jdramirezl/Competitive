#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> nums, int l, int r, int n){
    int left = l, right = r, mid;

    while(left <= right){
        mid = (left + right) / 2;

        if (nums[mid] > n) right = mid + 1;

        else if (nums[mid] < n) left = mid - 1;

        else return nums[mid];
    }

    return -1;
}

int main(){
    vector<int> nums;
    for(int i = 0; i < 10; ++i) nums.push_back(i);
    cout << binary_search(nums, 0, nums.size() - 1, 5) << endl;
}