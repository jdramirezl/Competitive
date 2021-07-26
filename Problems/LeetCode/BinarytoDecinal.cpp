// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Time complexity: O(n)

#include <bits/stdc++.h>

using namespace std;

class Solution {

    
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        
        ListNode *node = head;
        
        int size = 0;
        vector<int> nums;
        while(node){
            nums.push_back(node -> val);
            size++;
            node = node -> next;
        }
        
        int total = 0;
        for(int i = 0; i< size ; ++i){
            total += nums[size-1-i]*pow(2,i);
        }
        
        return total;
    }
};