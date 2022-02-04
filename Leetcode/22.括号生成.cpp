/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combs;
        string s;
        backtracking(combs, s, 0, n);
        return combs;
    }

private:
    void backtracking(vector<string> &combs, string &comb, int stack, int n) {
        if (comb.size() == 2*n) combs.push_back(comb);

        if (comb.size() + stack+2 <= 2*n) {
            comb.push_back('(');
            backtracking(combs, comb, stack+1, n);
            comb.pop_back();
        }

        if (stack) {
            comb.push_back(')');
            backtracking(combs, comb, stack-1, n);
            comb.pop_back();
        }
    }
};
// @lc code=end

