/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void aux(TreeNode* root, int level, vector<double> &ans, vector<double> &div){
        if(!root) return;
        if (level >= ans.size()) {ans.push_back(0); div.push_back(0);}
        div[level]++;
        if(div[level] == 1) ans[level] = root -> val;
        else ans[level] = (root -> val + (ans[level]*(div[level]-1)))/div[level];
        aux(root -> left, level + 1, ans, div);
        aux(root -> right, level + 1, ans, div);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans, div;
        aux(root, 0, ans, div);
        return ans;
    }
};