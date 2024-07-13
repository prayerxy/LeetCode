/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
/*回文序列*/
class Solution {
public:
    vector<pair<int,int>> Revert[1010];
    string s;
    //只管2个/3个求回文序列
    
    void setRevert(int j, int& length, pair<int, int>& maxpair) {
        //j是下标
        if (j - 1 < 0) {
            if (1 >= length) {
                length = 1;
                maxpair = { j,j };
            }
            Revert[j].push_back({ j,j });
            return;
        }
        if (s[j - 1] == s[j]) {
            if (2 >= length) {
                length = 2;
                maxpair = { j - 1,j };
            }
            if (j - 2 >= 0 && s[j - 2] == s[j]) {
                if (3 >= length) {
                    maxpair = { j - 2,j };
                    length = 3;
                }
                Revert[j].push_back({ j - 2,j });
            }
            Revert[j].push_back({ j - 1,j });
            return;
        }
        else if (j - 2 < 0) {
            if (1 >= length) {
                length = 1;
                maxpair = { j,j };
            }
            Revert[j].push_back({ j,j });
            return;
        }
        else if (s[j - 2] == s[j]) {
            if (3 >= length) {
                maxpair = { j - 2,j };
                length = 3;
            }
            Revert[j].push_back({ j - 2,j });
            return;
        }
        else {
            if (1 >= length) {
                length = 1;
                maxpair = { j,j };
            }
            Revert[j].push_back({ j,j });
        }
    }
    string longestPalindrome(string s2) {
        s = s2;
        int n = s.size();
        s = s;
        int maxlen = 0;
        pair<int, int>max_pair;
        for (int i = 0; i < n; i++) {
            //先把3个以内的子串处理完毕
            setRevert(i, maxlen, max_pair);
            if (i == 0)continue;
            //利用前一个递推
            for (auto k : Revert[i - 1]) {
                int t1 = k.first;
                int t2 = k.second;
                if(i-t1+1<=2)continue;
                if (t1 - 1 >= 0 && (s[i] == s[t1 - 1]) && t2 == i - 1) {
                    t1 = t1 - 1;
                    t2 = i;
                    Revert[i].push_back({ t1,i });
                    if (t2 - t1 + 1 >= maxlen) {
                        maxlen = t2 - t1 + 1;
                        max_pair = { t1,t2 };
                    }
                }
            }

        }
        return s.substr(max_pair.first, max_pair.second - max_pair.first + 1);
    }
};
// @lc code=end

