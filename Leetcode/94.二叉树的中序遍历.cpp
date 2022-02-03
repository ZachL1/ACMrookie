/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> visit;
        mid_visit(root, visit);
        return visit;
    }

private:
    void mid_visit(TreeNode* root, vector<int> &visit) {
        if (!root) return;
        mid_visit(root->left, visit);
        visit.push_back(root->val);
        mid_visit(root->right, visit);
    }
};
// @lc code=end

