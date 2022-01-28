/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yang(numRows);
        yang[0].push_back(1);
        for (int i = 1; i < numRows; ++i) {
            int cur_row = i + 1;
            yang[i].push_back(1);
            for (int j = 1; j < cur_row - 1; ++j) {
                int pre_i = i - 1;
                yang[i].push_back(yang[pre_i][j-1] + yang[pre_i][j]);
            }
            yang[i].push_back(1);
        }
        return yang;
    }
};
// @lc code=end

