/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;

// 暴力 + 剪枝
class Solution {
public:
    string longestPalindrome(string s) {
        str = s;
        int maxl, maxr;
        for (int l = 0; l < s.size(); ++l) {
            for (int r = l; r < s.size(); ++r) {
                // 剪枝
                if ((r-l > maxr-maxl) && isPalindrome(l, r)) {
                    maxr = r;
                    maxl = l;
                }
            }
        }
        return s.substr(maxl, maxr-maxl+1);
    }
private:
    string str;
    bool isPalindrome(int l, int r) {
        while (str[l] == str[r]) {
            if (l++ >= r--) return true;
        }
        return false;
    }
};
// @lc code=end

