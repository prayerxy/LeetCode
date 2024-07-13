/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
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
#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    typedef long long LL;
    typedef pair<int,int> PII;
    int targetSum;
    int count=0;
    void dfs(TreeNode*u,vector<LL>tmp){
        if(!u)return;
        for(int i=0;i<tmp.size();i++){
            if(u->val+tmp[i]==targetSum){
                count++;
            }
            tmp[i]+=u->val;
        }
         tmp.push_back(u->val);
        if(u->val==targetSum)count++;
        dfs(u->left,tmp);
        dfs(u->right,tmp);
    }
    int pathSum(TreeNode* root, int targetSum) {
        this->targetSum=targetSum;
        vector<LL>tmp={};
        dfs(root,tmp);
        return count;
    }
};
// @lc code=end

