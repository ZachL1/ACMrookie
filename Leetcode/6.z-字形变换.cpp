/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string newStr(s);
        int i = 0;

        for (int row = 1; row <= numRows; ++row) {
            int down = row - 1;
            while (down < s.size()) {
                newStr[i++] = s[down];

                int up = down + (numRows - row) * 2;
                if (row == numRows) up = down + (row - 1) * 2;
                if (up < s.size()) newStr[i++] = s[up];

                down = up + (row - 1) * 2;
                if (row == 1) down = up + (numRows - row) * 2;
            }
        }
        return newStr;
    }
};
// @lc code=end

