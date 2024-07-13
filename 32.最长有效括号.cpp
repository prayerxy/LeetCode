/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//时间复杂度较高
class Solution {
public:
    int maxlen = -1;
    int f1[30010];
    int t1[30010];
    int longestValidParentheses(string s) {
        maxlen = 0;
        int s_len = s.length();
        for (int i = 0; i < s_len - 1; i++) {
            int j = i + 1;
            if (s[i] == '(' && s[j] == ')') {
                f1[i] = j;
                t1[j] = 2;
                maxlen = 2;
            }
        }
        for (int len = 4; len <= s_len; len += 2) {
            for (int i = 0; i < s_len - 1 && i + len - 1 < s_len; i++) {
                int j = i + len - 1;
                //第一种情况 往后面加个括号
                if (f1[i] > 0) {
                    int ne = f1[i];
                    if (f1[ne + 1] == j) {
                        t1[j] = len;
                        f1[i] = j;
                        maxlen = max(t1[j], maxlen);
                    }
                }
                //第二种
                else if (f1[i + 1] > 0) {
                    int ne = f1[i + 1];
                    if (ne == j - 1 && s[i] == '(' && s[j] == ')') {
                        f1[i] = j;
                        t1[j] = len;
                        maxlen = max(t1[j], maxlen);
                    }
                }
            }
        }
        return maxlen;
    }
};

//第二种
class Solution {
public:
    vector<int> f;
    int longestValidParentheses(string s) {
        int n = s.size();
        f.resize(n,1);
        stack<int> stk;
        for (int i = 0;i < n;i++)
        {
            char x = s[i];
            if (x == '(')
            {
                stk.push(i);
                continue;
            }
            if (stk.size() and s[stk.top()] == '(')
            {
                f[i] = 0;
                f[stk.top()] = 0;
                stk.pop();
            }
        }
        int ans = 0,j = 0;
        for (int i = 0;i < n;i++)
        {
            // cout << f[i] << " ";
            if (f[i] == 1) 
            {
                j = 0;
                continue;
            }
            j++;
            ans = max(ans,j);
        }
        return ans;
    }
};


class Solution {
public:
    int get_answer(string s) {
        int n = s.size();
        int ans = 0, left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                ans = max(ans, left * 2);
            } else if (right > left) {
                left = right = 0;
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        int ans = get_answer(s);
        for (auto &c: s) {
            if (c == '(') c = ')';
            else c = '(';
        }
        reverse(s.begin(), s.end());
        ans = max(ans, get_answer(s));
        return ans;
    }
};
// @lc code=end

