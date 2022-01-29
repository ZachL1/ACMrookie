/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> nums(m+n);
        for (int i = 0, j = 0; i < m || j < n; ) {
            if (j==n || (i<m && nums1[i] < nums2[j])) {
                nums[i+j] = nums1[i];
                ++i;
            }
            else {
                nums[i+j] = nums2[j];
                ++j;
            }
        }
        int mn = m + n;
        if (mn & 1) return nums[mn / 2];
        return double(nums[mn/2 - 1] + nums[mn/2]) / 2;
    }
};
// @lc code=end

