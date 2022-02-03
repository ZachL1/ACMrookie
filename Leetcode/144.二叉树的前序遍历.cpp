/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        visit(root);
        return visit_list;
    }

private:
    vector<int> visit_list;
    void visit(TreeNode* subRoot) {
        if (!subRoot) return;
        visit_list.push_back(subRoot->val);
        visit(subRoot->left);
        visit(subRoot->right);
    }
};
// @lc code=end

