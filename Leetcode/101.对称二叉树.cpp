/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
        // return iterate(root);
    }
private:
    // 递归解法
    bool isSym(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        else if (t1 && t2) {
            if (t1->val == t2->val && 
                isSym(t1->left, t2->right) && isSym(t1->right, t2->left)) return true;
        }
        
        return false;
    }

    // 迭代解法
    bool iterate(TreeNode* root) {
        queue<TreeNode *> nodes;
        nodes.push(root->left);
        nodes.push(root->right);

        while (!nodes.empty()) {
            TreeNode *t1 = nodes.front(); nodes.pop();
            TreeNode *t2 = nodes.front(); nodes.pop();

            if (!t1 && !t2) continue;
            else if (t1 && t2) {
                if (t1->val != t2->val) return false;
                // 以相反的顺序将节点push到队列中
                // 如果树对称，则每次从队列出队的两个节点都是相等的
                nodes.push(t1->left);
                nodes.push(t2->right);
                nodes.push(t1->right);
                nodes.push(t2->left);
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end

