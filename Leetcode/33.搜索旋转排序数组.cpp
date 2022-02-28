/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int m = 0;
        while (l < r) {
            m = (l + r) / 2;
            if (l+1 == r) break;
            if (nums[l] < nums[m]) l = m;
            else r = m;
        }
        // return m;
        if (nums[0] < nums[n-1]) m = n-1;
        
        if (target >= nums[0]) return binary(nums, 0, m, target);
        else if (target <= nums[n-1]) return binary(nums, m+1, n-1, target);
        else return -1;
    }
    
    int binary(vector<int>& nums, int l, int r, int tar) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == tar) return m;
            
            if (nums[m] < tar) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};
// @lc code=end

