/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isNeg = x < 0;

        int maxInt = ~ (1 << 31);
        int minInt = 1 << 31;
        string strX = to_string(x);

        int reverse = 0;
        for (int i = strX.size()-1; i >= 0; --i) {
            if (isNeg) {
                if (!i) break;
                if ((minInt + int(strX[i] - '0')) / 10 > reverse) return 0;
                reverse = reverse * 10 - int(strX[i] - '0');
            }
            else {
                if ((maxInt - int(strX[i] - '0')) / 10 < reverse) return 0;
                reverse = reverse * 10 + long(strX[i] - '0');
            }
        }
        return reverse;
    }
};
// @lc code=end

