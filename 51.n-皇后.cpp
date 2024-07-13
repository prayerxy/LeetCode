/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
//dfs n皇后问题
class Solution {
public:
    static const int N=10;
    int g[N];
    int col[N],dg[2*N+1],udg[2*N+1];
    int n;
    vector<vector<string>>res;
    void dfs(int u){
        if(u==n){
            vector<string>tmp;
            for(int i=0;i<n;i++){
                string t;
                for(int j=0;j<n;j++){
                    if(g[i]==j)t+='Q';
                    else t+='.';
                }
                tmp.push_back(t);
            }
            res.push_back(tmp);
            return;
        }
        //每一行选择一个列 N种情况  做3个选择筛选 
        //每一行一定可以选到一个列 所以只有选择的一种可能，不可能无选择
        for(int i=0;i<n;i++){
            if(!col[i]&&!dg[u+i]&&!udg[u-i+n]){
                col[i]=dg[u+i]=udg[u-i+n]=1;
                g[u]=i;
                dfs(u+1);
                col[i]=dg[u+i]=udg[u-i+n]=0;
                g[u]=-1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        dfs(0);
        return res;
    }
};
// @lc code=end

