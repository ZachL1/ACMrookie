/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> hash_rol, hash_col;
        vector<unordered_map<char, int>> block(3);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.' && hash_rol[board[i][j]]++)
                    return false;
                if (board[j][i] != '.' && hash_col[board[j][i]]++)
                    return false;
                if (board[i][j] != '.' && block[j/3][board[i][j]]++)
                    return false;
            }
            hash_rol.clear();
            hash_col.clear();
            if (i % 3 == 2) {
                for (auto& m : block) m.clear();
            }
        }
        return true;
    }
};
// @lc code=end

