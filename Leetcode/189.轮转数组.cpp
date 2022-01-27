/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count = nums.size();
        for (int i = 0; count < nums.size(); ++i) {
            int temp = nums[i];
            int new_i = i;
            while (true) {
                --count;
                if (new_i == k) {
                    nums[new_i] = temp;
                    break;
                }
                int old_i = ( new_i - k + nums.size() ) % nums.size();
                nums[new_i] = nums[old_i];
                new_i = old_i;
            }
            if (!count) break;
        }

        // 蠢的解法
        // k %= nums.size();
        // vector<int> temp_nums(nums);
        // for (int i = 0; i < nums.size(); ++i) {
        //     nums[i] = temp_nums[( i - k + nums.size() ) % nums.size()];
        // }
    }
};
// @lc code=end

