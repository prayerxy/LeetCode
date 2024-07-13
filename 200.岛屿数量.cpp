/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
//dfs解法1
// class Solution {
// public:
//     typedef pair<int,int> PII;
//     int st[302][302];
//     int n,m;
//     int idx=0;
//     void dfs(int i, int j,vector<vector<char>>&grid) {
//         st[i][j] = 1;
//         grid[i][j]='0';
//         int dy[4] = { -1,1,0,0 };
//         int dx[4] = { 0,0,-1,1 };
//         for (int k = 0; k < 4; k++) {
//             int x_t = i + dx[k];
//             int y_t = j + dy[k];
//             if (x_t >= 0 && x_t < m && y_t >= 0 && y_t < n) {
//                 if (st[x_t][y_t])continue;
//                 if(grid[x_t][y_t]=='0')continue;
//                 dfs(x_t, y_t,grid);
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         this->n=grid[0].size();
//         this->m=grid.size();
//         memset(st,0,sizeof st);
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     idx++;
//                     dfs(i,j,grid);
//                 }
//             }
//         }
//         return idx;
//     }
// };


//并查集解法2

// @lc code=end

