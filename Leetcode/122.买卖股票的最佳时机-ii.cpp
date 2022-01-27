/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 * 贪心
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_min = prices[0];
        int ans_sum = 0;
        for (int day = 1; day < prices.size(); ++day) {
            if (prices[day] > prices_min) {
                ans_sum += prices[day] - prices_min;
            }
            prices_min = prices[day];
        }
        return ans_sum;
    }
};
// @lc code=end

