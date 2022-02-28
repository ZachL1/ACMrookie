/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int l = my_lower_bound(nums, target), 
            r = my_lower_bound(nums, target+1);
        
        if (l == -1) return {-1, -1};
        if (r == -1) r = nums.size();

        if (nums[l] != target) return {-1, -1};
        return {l, r-1};
    }

    int my_lower_bound(vector<int>& nums, int target) {
        // 找到第一个不小于 target 的值的索引
        int n = nums.size(), left = -1, right = n-1;

        while (left+1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) left = mid;
            else right = mid;
        }
        if (nums[left+1] < target) return -1; // 如果最大的数比 target 还小
        return left + 1;
    }
};
// @lc code=end

