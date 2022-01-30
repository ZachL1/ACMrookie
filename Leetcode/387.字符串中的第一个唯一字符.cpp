/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash;
        // memset(hash, 0, sizeof hash);
        for (char &i : s) {
            hash[i]++;
        }
        for (char &i : s) {
            if (hash[i] == 1) return s.find(i);
        }
        return -1;
    }
};
// @lc code=end

