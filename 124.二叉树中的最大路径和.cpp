/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<bits/stdc++.h>
using namespace std;
/*最大路径和*/
class Solution {
public:
    int maxlength=-0x3f3f3f;
    int dfs(TreeNode*u){
        if(!u)return 0;
        int sum=u->val;
        int a=dfs(u->left);
        int b=dfs(u->right);
        maxlength=max(sum,maxlength);
        maxlength=max(sum+a+b,maxlength);
        maxlength=max(sum+b,maxlength);
        maxlength=max(sum+a,maxlength);

        int retval=max(sum+a,sum+b);
        retval=max(retval,sum);//注意还要再比较一次

        return retval;//子树中的最大值
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxlength;
    };
};
// @lc code=end

