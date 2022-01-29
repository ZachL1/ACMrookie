/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; // 存储答案
        unordered_map<int, int> hash_nums; // 存储 nums 的哈希表
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash_nums.find(target - nums[i]);
            if (it != hash_nums.end()) {
                return {it->second, i};
            }
            hash_nums[nums[i]] = i;
        }
        return ans;
    }
};
// @lc code=end

