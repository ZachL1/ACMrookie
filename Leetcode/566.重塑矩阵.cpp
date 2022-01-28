/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r*c != m*n) return mat;

        // vector<int> row(c);
        vector<vector<int>> new_mat(r);
        for (int i = 0; i < m*n; ++i) {
            new_mat[i/c].push_back(mat[i/n][i%n]);
        }
        return new_mat;
    }
};
// @lc code=end

