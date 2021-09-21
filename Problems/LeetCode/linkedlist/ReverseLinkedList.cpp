/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *last, *curr, *next;
        if(!head) return head;
        last = nullptr; 
        curr = head; //1
        next = curr -> next; //2

        while(curr){
            curr -> next = last;

            last =  curr; // 1
            curr = next; // 2
            if(next)next = curr -> next; // 3
        }
        
        return last;
    }
};