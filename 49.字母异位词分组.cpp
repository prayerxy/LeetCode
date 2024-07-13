/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
// class Solution {

// public:
//     unordered_map<string,int>tmp;
//     int idx=0;
//     vector<pair<char,int>>origin;
//     vector<vector<string>>res;
//     void init(){
//         for(auto c='a';c<='z';c++){
//             origin.push_back({c,0});
//         }
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         init();
//         for(auto s:strs){
//             vector<pair<char,int>>ss=origin;
//             string ss_tmp;
//             for(auto cha:s){
//                 ss[cha-'a'].second++;
//             }
//             for(auto ele:ss){
//                 ss_tmp+=ele.first+ele.second;
//             }
//             if(tmp.find(ss_tmp)!=tmp.end()){
//                 res[tmp[ss_tmp]].push_back(s);
//             }else{
//                 tmp[ss_tmp]=idx++;
//                 vector<string>ts;
//                 ts.push_back(s);
//                 res.push_back(ts);
//             }
//         }
//         return res;
        
//     }
// };

class Solution {

public:
    //归并排序
    char tmp[110];
    void merge_sort(string& q,int l,int r){
        if(l>=r)return;
        int mid=l+r>>1;
        merge_sort(q,l,mid);merge_sort(q,mid+1,r);

        int i=l,j=mid+1,k=0;
        while(i<=mid&&j<=r){
            if(q[i]<=q[j])tmp[k++]=q[i++];
            else tmp[k++]=q[j++];
        }
        while(i<=mid)tmp[k++]=q[i++];
        while(j<=r)tmp[k++]=q[j++];
        for(int i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];
    };
    unordered_map<string,int>temp;
    int idx=0;
    vector<vector<string>>res;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto s:strs){
            //sort
            string key=s;
            // sort(key.begin(),key.end());
            merge_sort(key,0,key.size()-1);
            if(temp.find(key)!=temp.end()){
                res[temp[key]].push_back(s);
            }else{
                vector<string>ss_tmp={s};
                temp[key]=idx++;
                res.push_back(ss_tmp);
            }
        }
        return res;
        
    }
};
// @lc code=end

