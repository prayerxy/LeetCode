/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


//暴力法
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         //遍历子串
//         int res[50010]={0};
//         int out=0;
//         for(int i=0;i<s.length();i++){
//             if(i!=0&&res[i-1]>0){
//                 res[i]=res[i-1]-1;
//                 string tmp=s.substr(i,res[i]);
//                 for(int j=i+res[i-1]-1;j<s.length();j++){
//                     if(tmp.find(s[j])==tmp.npos){
//                         tmp.push_back(s[j]);
//                         res[i]++;
//                     }
//                     else break;
//                 }
//             }
//             else{
//                 string tmp;
//                 tmp.push_back(s[i]);
//                 res[i]=1;
//                 for(int j=i+1;j<s.length();j++){
//                     if(tmp.find(s[j])==tmp.npos){
//                         tmp.push_back(s[j]);
//                         res[i]++;
//                     }
//                     else break;
//                 }
//             }
//             if(res[i]>out){
//                 out=res[i];
//             }
//         }
//         return out;
//     }
// };


//滑动窗口法  队列法则
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.length()<=0)return 0;
       unordered_set<char>map;
       int out=0;
       int front=0;
       //abcabdef
       for(int i=0;i<s.length();i++){
            //如果相同把窗口右移  右移可能移动多次 直至队列中无2个元素相同
            while(map.find(s[i])!=map.end()){
                map.erase(s[front]);
                front++;
            }
            
            out=max(out,i-front+1);
            map.insert(s[i]);

       }
        return out;
    }
};


// @lc code=end

