/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return combinations;
        back(digits, "", 0);
        return combinations;
    }

private:
    vector<string> combinations, 
                hash = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void back(string &digits, string combination, int i) {
        if (i == digits.size()) {
            combinations.push_back(combination);
            return;
        }

        int num = digits[i] - '2';
        for (char c : hash[num]) {
            combination.push_back(c);
            back(digits, combination, i+1);
            combination.pop_back();
        }
    }
};
// @lc code=end

