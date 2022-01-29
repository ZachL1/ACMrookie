/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row, col;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for (int i : row) 
            for (int &c : matrix[i]) c = 0;
        for (auto &r : matrix) 
            for (int j : col) r[j] = 0;
        
        
    }
};
// @lc code=end

