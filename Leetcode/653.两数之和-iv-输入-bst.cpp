/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         vector<int> v;
//         return findk(root, k, v);
//     }

//     bool findk(TreeNode* root, int k, vector<int> &v) {
//         if (!root) return false;

//         if (find(v.begin(), v.end(), root->val) != v.end()) return true;
//         v.push_back(k - root->val);
//         return findk(root->left, k, v) || findk(root->right, k, v);
//     }
// };

// 使用 vector find 太蠢了，时间复杂度高
// 使用 set 哈希即可
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> v;
        return findk(root, k, v);
    }

    bool findk(TreeNode* root, int k, unordered_set<int> &v) {
        if (!root) return false;

        if (v.find(root->val) != v.end()) return true;
        v.insert(k - root->val);
        return findk(root->left, k, v) || findk(root->right, k, v);
    }
};
// @lc code=end

