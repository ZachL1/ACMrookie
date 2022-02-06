/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return root = new TreeNode(val);

        TreeNode *node = root;
        while (true) {
            if (node->val > val) {
                if (!node->left) {
                    node->left = new TreeNode(val);
                    return root;
                }
                node = node->left;
            }
            else {
                if (!node->right) {
                    node->right = new TreeNode(val);
                    return root;
                }
                node = node->right;
            }
        }
    }
};
// @lc code=end

