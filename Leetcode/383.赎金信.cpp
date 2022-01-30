/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash1[26], hash2[26];
        memset(hash1, 0, sizeof hash1);
        memset(hash2, 0, sizeof hash2);
        for (char& i : ransomNote) ++hash1[i-'a'];
        for (char& i : magazine) ++hash2[i-'a'];
        for (int i = 0; i < 26; ++i) {
            if (hash1[i] > hash2[i]) return false;
        }
        return true;
    }
};
// @lc code=end

