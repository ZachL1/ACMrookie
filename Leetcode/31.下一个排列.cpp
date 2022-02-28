/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
				
        int maxn = 0, mini = -1;
        int i = nums.size() - 1;
        for(; i >= 0; --i){
            if (maxn > nums[i]) break;
            maxn = max(maxn, nums[i]);
            
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        for (int ii = nums.size()-1; ii > i; --ii){
            if(nums[ii] > nums[i]){
                if(mini == -1) mini = ii;
                mini = nums[ii] < nums[mini] ? ii : mini;
            }
        }
        
        if(mini == -1) return;
        swap(nums[i], nums[mini]);
        sort(nums.begin()+i+1, nums.end());
    }
};
// @lc code=end

