/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    typedef long long LL;
    unordered_map<TreeNode*,TreeNode*>fa;
    unordered_map<int,bool>vis;
    int idx=1;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //bfs一遍
        queue<TreeNode*>s;
        s.push(root);
        fa.insert({root,nullptr});
        int flag1=0,flag2=0;
        if(p==root)flag1=1;
        if(q==root)flag2=1;
        while(!s.empty()){
            if(flag1&&flag2)break;
            TreeNode* t=s.front();
            s.pop();
            if(t->left){
                fa.insert({t->left,t});
                s.push(t->left);
                if(p==t->left)flag1=1;
            }
            if(t->right){
                fa.insert({t->right,t});
                s.push(t->right);
                if(q==t->right)flag2=1;
            }
        }
        unordered_set<TreeNode*>visited;
        while(p){
            vis[p->val]=1;
            p=fa[p];
        }
        while(1){
            if(vis[q->val]==1){
                return q;
            }
            q=fa[q];
        }
        return nullptr;
    }
};



// @lc code=end

