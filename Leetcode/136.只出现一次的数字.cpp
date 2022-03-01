/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int start = 0;
        for (int num : nums) {
            start ^= num;
        }

        return start;
    }
};
// @lc code=end

