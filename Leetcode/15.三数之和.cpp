/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > groups;
        if (nums.empty()) return groups;

        sort(nums.begin(), nums.end());
        int n = nums.size(), jump = nums[0];

        for (int i = 0; i < n-2;) {
            int l = i+1, r = n-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    groups.push_back({nums[i], nums[l], nums[r]});
                    int jump2 = nums[l];
                    while (l < r && jump2 == nums[l]) ++l;
                }
                else if (sum > 0) --r;
                else ++l;
            }
                
            while (i < n && nums[i] == jump) ++i;
            jump = nums[i];
        }

        return groups;
    }
};
// @lc code=end

