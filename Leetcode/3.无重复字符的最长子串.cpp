/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
using namespace std;
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;

        int l = 0, r = 0;
        int sub_length = 0;

        unordered_map<char, int> hash;
        // memset(hash, 0, sizeof hash);

        ++hash[s[r++]];
        while (r < s.size()) {
            if (hash[s[r]]++) {
                sub_length = max(sub_length, r-l);
                while (s[l] != s[r])
                    --hash[s[l++]];
                --hash[s[l++]];
            }
            ++r;
        }
        return max(sub_length, r-l);
    }
};
// @lc code=end

