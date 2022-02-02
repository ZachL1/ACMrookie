/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> left = {{'(', 1}, {'{', 2}, {'[', 3}};
        unordered_map<char, int> right = {{')', 1}, {'}', 2}, {']', 3}};
        stack<char> sta;
        for (char &c : s) {
            if (left.find(c) != left.end()) sta.push(left[c]);
            else {
                if (sta.empty() || sta.top() != right[c]) return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};
// @lc code=end

