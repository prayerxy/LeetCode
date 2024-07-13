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
    //dfs自下往上，刚好是最近公共祖先
    TreeNode* dfs(TreeNode*u,TreeNode*p,TreeNode*q){
        if(!u)return nullptr;
        if(u==p||u==q)return u;
        auto t1= dfs(u->left,p,q);
        auto t2=dfs(u->right,p,q);
        if(t1&&t2)return u;
        if(t1)return t1;
        if(t2)return t2;
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        return dfs(root,p,q);
        
    }   
};


// 解决问题的临界是某个节点 左边有p 右边有q 或是 自己是p 左或右有q
// --- 减小规模
// 应该这样定义函数功能：1. p q都能找到 返回最近公共祖先 2. p q 找到一个，返回p q 3. 都没找到 返回null