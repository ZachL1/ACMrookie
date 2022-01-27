/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
#include <iostream>>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prices_max = prices[n-1];
        int ans_max = 0;
        for (int i = n-2; i >= 0; --i) {
            prices_max = max(prices_max, prices[i]);
            ans_max = max(ans_max, prices_max - prices[i]);
        }
        return ans_max;
    }
};
// @lc code=end

