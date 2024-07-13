/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
//重点：采用动态规划预处理出回文序列数组f[i][j]，判断s[i,..,j]之间是否回文
#include<bits/stdc++.h>
using namespace std;
//完全dfs树形遍历，时间复杂度超高
// class Solution {
// public:
//     //判断是否回文
//     bool check(string s,int i,int j){
//         int len=j-i+1;
//         int init=len%2==0?len/2:(len-1)/2;
//         int flag=1;
//         for(int idx=i;idx<i+len;idx++){
//             if(s[idx]!=s[j-idx+i]){
//                 flag=0;
//                 break;
//             }
//         }
//         return flag;
//     }
//     map<int,string>record;
//     vector<vector<string>>res;
//     string s;
//     int ii=0;
//     //dfs求出所有可能情况  针对每个字符
//     void dfs(int u,int prev){
//         if(u==s.length()){
//             vector<string>t;
//             for(auto ele:record){
//                 if(ele.second!=""){
//                     t.push_back(ele.second);
//                 }
//             }
            
//                 res.push_back(t);
 
            
//             return;
//         }
//         //和前面的字符成为一个集合，或者不成为单独开一个
//         prev++;
//         //单独开需要检查前面是否回文
//         string tmp=record[prev-1];
//         if(tmp==""||check(tmp,0,tmp.length()-1)){
//             record[prev].push_back(s[u]);
//             dfs(u+1,prev);//单独开一个
//             record[prev].pop_back();
//         }
//         prev--;
//         //和前面的字符成为一个集合
//         if(u!=0){
//             record[prev].push_back(s[u]);
//             string tmp=record[prev];
//             if(u==s.length()-1){
//                 if(!check(tmp,0,tmp.length()-1)){record[prev].pop_back();return;}
//             }
//             dfs(u+1,prev);
//             record[prev].pop_back();
//         }

//     }
//     vector<vector<string>> partition(string s) {
//         this->s=s;
//         dfs(0,0);
//         return res;
//     }
// };
class Solution {
public:
    //先预处理得到f数组
    int f[20][20];//f[i][j]->s[i,..,j]是否回文
    //采取动态规划方式
    vector<vector<string>>res;
    string s;
    vector<string>ans;
    void dfs(int u){
        if(u==s.length()){
            res.push_back(ans);
            return;
        }
        //从u到s.length()之间每一个子串，若为回文序列再递归
        for(int j=u;j<s.length();j++){
            if(f[u][j]){
                ans.push_back(s.substr(u,j-u+1));
                //前面j个是另一个集合  从j+1开始
                dfs(j+1);
                ans.pop_back();
            }
        }
    }
  
    vector<vector<string>> partition(string s) {
        this->s=s;
        for(int i=0;i<s.length();i++){
            f[i][i]=1;
        }
        for(int len=1;len<s.length();len++){
            for(int i=0;i+len<s.length();i++){
                int j=i+len;
                if(i+1>=j-1){f[i+1][j-1]=1;}
                f[i][j]=f[i+1][j-1]&&(s[i]==s[j]);
            }
        }
        dfs(0);
        return res;
    }
};
// @lc code=end

