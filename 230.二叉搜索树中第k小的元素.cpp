/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    unordered_map<int,TreeNode*>order;
    int idx=1;
    void search(TreeNode*u,int k){
        if(!u)return;
        //减枝
        if(idx>k)return;
        search(u->left,k);
        order.insert({idx++,u});
        search(u->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        //中序遍历  左根右
        search(root,k);
        return order[k]->val;
    }
};
// @lc code=end

