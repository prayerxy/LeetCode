/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
//回溯类  单词搜索

// class Solution {
// public:
//     string word;
//     vector<vector<char>> board;
//     int st[10][10];
//     int flag=0;
//     void dfs(int u,vector<pair<int,int>>init){
//         if(u==word.size()){
//             flag=1;
//             return;
//         }
//         if(flag)return;
//         if(init.size()==0)return;
//         for(auto tmp:init){
//             int idx_i=tmp.first;
//             int idx_j=tmp.second;
//             st[idx_i][idx_j]=1;
//             int dx[4]={0,0,-1,1};
//             int dy[4]={-1,1,0,0};
//             vector<pair<int,int>>next;
//             for(int i=0;i<4;i++){
//                 int n_i=idx_i+dx[i];
//                 int n_j=idx_j+dy[i];
//                 if(n_i>=0&&n_i<board.size()&&n_j>=0&&n_j<board[0].size()){
//                     if(board[n_i][n_j]==word[u+1]&&st[n_i][n_j]==0){
//                         next.push_back({n_i,n_j});
//                     }
//                 }
//             }
//             dfs(u+1,next);
//             if(flag)
//             st[idx_i][idx_j]=0;
//         }
        
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         this->board=board;
//         this->word=word;
//         vector<pair<int,int>>init;
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 if(board[i][j]==word[0]){
//                     init.push_back({i,j});
//                 }
//             }
//         }
//         dfs(0,init);
//         return flag;
//     }
// };

//不要用Vector存储，直接循环进入即可
class Solution {
public:
    string word;
    vector<vector<char>> board;
    int st[10][10];
    int flag=0;
    void dfs(int u,int x,int y){
        if(u==word.size()-1){
            flag=1;
            return;
        }
        if(flag)return;

        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        for(int i=0;i<4;i++){
            int n_i=x+dx[i];
            int n_j=y+dy[i];
            if(n_i>=0&&n_i<board.size()&&n_j>=0&&n_j<board[0].size()){
                if(board[n_i][n_j]==word[u+1]&&st[n_i][n_j]==0){
                    st[n_i][n_j]=1;
                    dfs(u+1,n_i,n_j);
                    st[n_i][n_j]=0;
                    if (flag) return;
                }
            }
        }
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        this->word=word;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    st[i][j]=1;
                    dfs(0,i,j);
                    st[i][j]=0;
                }
            }
        }
        return flag;
    }
};
// @lc code=end

