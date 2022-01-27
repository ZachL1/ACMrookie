/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> hash1, hash2;
        for (int i : nums1) {
            hash1[i]++;
        }
        for (int i : nums2) {
            hash2[i]++;
        }
        for (auto& it : hash1) {
            int comm = it.first;
            if (hash2.find(comm) != hash2.end()) {
                for (int i=0; i < min(it.second, hash2[comm]); ++i) {
                    ans.push_back(comm);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

