/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 * 主要考察二分查找
 */

// @lc code=start
// #include<vector>
// #include<iostream>
// using namespace std;
// class Solution {
// public:

//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         //两个数组的中位数求解   暴力归并
//         //我真服了 全部是边界问题
//         double res;
//         int i=0,j=0;
//         int pivot=(nums1.size()+nums2.size())/2;
//         while (i + j < pivot && i < nums1.size() && j < nums2.size()) {
//             if (nums1[i] <= nums2[j]) { i++; }
//             else { j++; }
//         }
//         while (i + j < pivot && i < nums1.size()) { i++; }
//         while (i + j < pivot && j < nums2.size()) { j++; }
//         if((nums1.size()+nums2.size())%2){
//             if(nums1.size()==0)return nums2[j];
//             if(nums2.size()==0)return nums1[i];
            
//             if(i==nums1.size())return nums2[j];
//             if(j==nums2.size())return nums1[i];
//             if(nums1[i]<nums2[j])return nums1[i];
//             else return nums2[j];
//         }
//         else{
//             int t1,t2;
//             if(i==0)t1=nums2[j-1];
//             else if(j==0)t1=nums1[i-1];
//             else {
//                 t1=nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1];
//             }
//             if(i==nums1.size())t2=nums2[j];
//             else if(j==nums2.size())t2=nums1[i];
//             else{
//                 t2=nums1[i]>nums2[j]?nums2[j]:nums1[i];
//             }
//             res=double(t1+t2)/2;
//             return res;
//         }
//     }
// };


//O(log(m+n))解法
#include<bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int getKth(vector<int>& nums1, vector<int>& nums2, int k) {
        //找到第k大的数字
        int n = nums1.size(); int m = nums2.size();
        int lg=log2(n);//找到n的二进制最高位的位数
        int len = 1<<lg;//找到n的二进制最高位对应的数 15->最高位对应8 8+4+2+1=15
        int p = 0;
        int flag=1;
        for(;;len>>=1) {//每一次减少一半 8 1 7=16  而8/2 二进制最高位置0 4+2+1=7刚好可以遍历到右边所有值
            int q = len + p;
            if (q >= n) {  continue; }//二进制最高位置0 还可以满足n-1的下标  二进制数字
            int overs1 = n - 1 - q;
            if (overs1 > k) { p=q; continue; }//右移+左移
            int j = m - 1 - (k - overs1);
            if (j == -1) {
                if (nums2[0] >= nums1[q]) { return nums1[q]; }

            }
            else if (j >= 0) {
                if (nums1[q] < nums2[j]) {
                    //过小
                    p = q;
                }
                else if (j == m - 1 || nums1[q] <= nums2[j + 1]) {
                    return nums1[q];
                }
                
            }
            //说明要左移 for循环自动len>>=1
            if(len==0)return -1;
         
        }
        // if(len==0){
        //     int over1=n-p-1;
        //     int j=m-1-(k-over1);
        //     if(j==-1){
        //         if(nums2[0]>=nums1[p])
        //         return nums1[p];
        //     }
        //     else if(j>=0){
        //         if(nums1[p]>=nums2[j]&&(j==m-1||nums1[p]<=nums2[j+1]))
        //         return nums1[p];
        //     }

        // }
        return -1;
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int sum = n + m;
        if (n && m) {
            if (sum & 1) {
                //奇数
                int ans = max(getKth(nums1, nums2, sum >> 1), getKth(nums2, nums1, sum >> 1));
                double a = 1.0 * ans;
                return a;
            }
            else {
                //偶数
                double a1 = max(getKth(nums1, nums2, sum >> 1), getKth(nums2, nums1, sum >> 1));
                double a2 = max(getKth(nums1, nums2, (sum >> 1) - 1), getKth(nums2, nums1, (sum >> 1) - 1));
                double h = (a1 + a2) / 2;
                return h;
            }
        }
        else if (n) {
            if (sum & 1) {
                return 1.0 * nums1[n >> 1];
            }
            else {
                return 0.5 * (nums1[n >> 1] + nums1[(n >> 1) - 1]);
            }
        }
        else if (m) {
            if (sum & 1)
                return 1.0 * nums2[m >> 1];
            else
                return 0.5 * (nums2[m >> 1] + nums2[(m >> 1) - 1]);
        }
        return 0;
    }
    
};
// @lc code=end

