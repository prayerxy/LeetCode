/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int,int> PII;
    int st[15][15];
    int count=0;
    int rotted=0;
    int level=0;
    //bfs 
    queue<pair<PII,int>>rot_q;
    

    int spread(int i,int j,int level,vector<vector<int>>&grid){
        st[i][j]=1;
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        int flag=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&!st[x][y]){
                st[x][y]=1;
                if(grid[x][y]==1){
                    rotted++;
                    grid[x][y]=2;
                    rot_q.push({{x,y},level});
                    flag++;
                }
            }
        }
        return flag;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)count++;
                if(grid[i][j]==2){
                    rot_q.push({{i,j},level});
                }
            }
        }
        while(!rot_q.empty()){
            auto ele=rot_q.front();
            level=max(ele.second,level);
            rot_q.pop();
            int t=spread(ele.first.first,ele.first.second,ele.second+1,grid);
        }
        if(rotted!=count)return -1;
        return level;
    }
};
// @lc code=end

