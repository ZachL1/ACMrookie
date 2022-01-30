/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash1[26], hash2[26];
        memset(hash1, 0, sizeof hash1);
        memset(hash2, 0, sizeof hash2);
        for (char& i : s) ++hash1[i-'a'];
        for (char& i : t) ++hash2[i-'a'];
        for (int i = 0; i < 26; ++i) {
            if (hash1[i] != hash2[i]) return false;
        }
        return true;
    }
};
// @lc code=end

