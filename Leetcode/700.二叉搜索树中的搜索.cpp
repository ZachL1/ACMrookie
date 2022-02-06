/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // if (!root || root->val == val) return root;

        // TreeNode *left = searchBST(root->left, val);
        // if (left) return left;
        // return searchBST(root->right, val); 

        // BST 左子树小，右子树大
        while (root && (root->val != val)) {
            if (val < root->val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};
// @lc code=end

