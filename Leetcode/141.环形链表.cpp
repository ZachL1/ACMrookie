/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode flag(100001);
        ListNode *nextNode = head->next;
        while (head) {
            if (head->val == flag.val) return true;
            head->next = &flag;
            head = nextNode;
            if (!head) break;
            nextNode = head->next;
        }
        return false;
    }
};
// @lc code=end

