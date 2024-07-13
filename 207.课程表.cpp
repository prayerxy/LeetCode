/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //入度
    int d[2010];
    int h[2010],ne[2010*2],e[2010*2];
    int idx=0;
    int count=0;
    int n;
    void add(int x,int y){
        e[idx]=y;
        ne[idx]=h[x];
        h[x]=idx++;
    }
    bool topsort(){
        queue<int>s;
        for(int i=0;i<n;i++){
            if(!d[i]){s.push(i);}
        }
        while(!s.empty()){
            auto t=s.front();
            count++;
            s.pop();
            for(int i=h[t];i!=-1;i=ne[i]){
                int n=e[i];
                d[n]--;
                if(d[n]==0)s.push(n);
            }
        }
        if(count==n)return 1;
        else return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //拓扑排序
        memset(d,0,sizeof d);
        memset(h,-1,sizeof h);
        this->n=numCourses;
        for(auto i:prerequisites){
            int a=i[0];
            int b=i[1];
            add(a,b);
            d[b]++;
        }
        return topsort();
    }
};
// @lc code=end

