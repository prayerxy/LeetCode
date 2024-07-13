/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
//
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//暴力枚举
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };

//哈希表  时间复杂度O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>smap;//可能有相同的值对应不同的索引
       //哈希表的查询与增加、删除是O(1)
       for(int i=0;i<nums.size();i++){
            auto it=smap.find(target-nums[i]);
            if(it!=smap.end()){
                return{i,it->second};
            }

            smap[nums[i]]=i;
       }
        return {};
    }
};
// @lc code=end

