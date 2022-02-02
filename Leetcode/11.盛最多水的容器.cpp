/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxV = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int l_height = height[l], r_height = height[r];
            maxV = max(maxV, (r - l) * min(l_height, r_height));
            if (l_height < r_height) {
                while (l < r && height[l] <= l_height) ++l;
            }
            else {
                while (l < r && height[r] <= r_height) --r;
            }
        }
        return maxV;
    }
};
// @lc code=end

