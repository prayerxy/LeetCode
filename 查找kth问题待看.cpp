// Amazon 34+; Google 16+; 字节跳动 10+; Facebook 7+; Microsoft 5+; Yahoo 4+; Baidu 2+; eBay 2+; Adobe 14+; Bloomberg 10+; Apple 41+;
// Uber 9+; LinkedIn 5+; PayPal 3+; Alibaba 2+; 
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    // 类型别名
    using Iter = std::vector<int>::iterator;

    // 查找第K个数
    int findKth(Iter ita, int m, Iter itb, int n, int k) {
        if (m < 0 || n < 0 || k <= 0) return 0;
        if (m > n) return findKth(itb, n, ita, m, k);
        if (m == 0) return itb[k-1];
        if (k == 1) return std::min(*ita, *itb);
        int xa = std::min(k/2, m), xb = k - xa;
        if (ita[xa-1] == itb[xb-1]) return ita[xa-1];
        if (ita[xa-1] < itb[xb-1]) return findKth(ita + xa, m-xa, itb, n, k-xa);
        else return findKth(ita, m, itb+xb, n-xb, k-xb);
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size(), n = (int)nums2.size();
        int cnt = m + n;
        if (cnt & 0x01) {
            return findKth(nums1.begin(), m, nums2.begin(), n,  cnt/2+1);
        } else {
            int x = findKth(nums1.begin(), m, nums2.begin(), n, cnt/2);
            int y = findKth(nums1.begin(), m, nums2.begin(), n, cnt/2+1);
            return (x + y) / 2.0;
        }
    }
};