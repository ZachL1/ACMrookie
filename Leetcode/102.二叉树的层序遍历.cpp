/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        queue<TreeNode *> node_queue;
        if (root) node_queue.push(root);

        while (!node_queue.empty()) {
            int n = node_queue.size(); // 每一层的节点个数

            ret.push_back(vector<int> ());
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = node_queue.front();
                ret.back().push_back(curr->val);
                if (curr->left) node_queue.push(curr->left);
                if (curr->right) node_queue.push(curr->right);
                node_queue.pop();
            }
        }
        return ret;
    }
};
// @lc code=end

