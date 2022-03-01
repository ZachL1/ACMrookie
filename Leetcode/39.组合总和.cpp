/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> candy;
        vector<vector<int>> ret;
        
        back(candidates, target, candy, 0, ret);
        return ret;
    }

    void back(vector<int>& candidates, int target, vector<int>& candy, int i, vector<vector<int>>& ret) {
        if (i >= candidates.size()) return;
        if (target < 0) return;

        if (!target) ret.push_back(candy);
        else {
            candy.push_back(candidates[i]);
            back(candidates, target - candidates[i], candy, i, ret);

            candy.pop_back();
            back(candidates, target, candy, i+1, ret);
        }
    }
};
// @lc code=end

