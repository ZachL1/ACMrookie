/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        stack<TreeNode*> nodes[2];
        if (root) nodes[0].push(root);
        bool l2r = true;
        while (!nodes[0].empty() || !nodes[1].empty()) {
            ret.push_back(vector<int> ());

            int curr = nodes[0].empty() ? 1 : 0;
            int other = nodes[0].empty() ? 0 : 1;
            while (!nodes[curr].empty()) {
                TreeNode* node = nodes[curr].top(); nodes[curr].pop();
                ret.back().push_back(node->val);
                if (l2r) { // 如果当前是从左到右，则先push左子树再push右子树
                    if (node->left) nodes[other].push(node->left);
                    if (node->right) nodes[other].push(node->right);
                }
                else {
                    if (node->right) nodes[other].push(node->right);
                    if (node->left) nodes[other].push(node->left);
                }
            }
            l2r = !l2r;
        }

        return ret;
    }
};
// @lc code=end

