/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//滑动窗口
//单调队列，窗口内部始终保持最老的在front，然后单调下降的趋势.因为如果最老的不最大，那没必要存储(只看窗口内最大值)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int back=-1;
        int front=-1;
        deque<int>q;//单调队列，把没有用的元素弹出
        vector<int>res;
        // 324567   注意队列中存储的是一个值单调的序列 队头最大  队尾最小  只需要最老且最大的 
        for(int i=0;i<nums.size();i++){
            if(q.size()&&i-k+1>q.front())q.pop_front();
            while(q.size()&&nums[q.back()]<=nums[i])q.pop_back();//不需要老且小的
            //直接插入最新至队尾
            q.push_back(i);
            if(i-k+1>=0){res.push_back(nums[q.front()]);}
        }
        return res;
    }
};
// @lc code=end

