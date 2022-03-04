/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& vec1, const vector<int>& vec2) { return *vec1.begin() < *vec2.begin(); });

        vector<vector<int>> ret;
        vector<int> curr = *intervals.begin(), next;
        for (int i = 1; i < intervals.size(); ++i) {
            next = intervals[i];
            if (curr[1] >= next[0]) {
                curr[1] = max(curr[1], next[1]);
            } else {
                ret.push_back(curr);
                curr = next;
            }
            if (i + 1 == intervals.size()) ret.push_back(curr);
        }
        return ret;
    }

    // static bool cmp(const vector<int>& vec1, const vector<int>& vec2) {
    //     return *vec1.begin() < *vec2.begin();
    // }
};
// @lc code=end

