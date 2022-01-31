/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) head = head->next;
        if (!head) return head;

        ListNode *pre = head, *curr = pre->next;
        while (curr) {
            if (curr->val == val) {
                curr = curr->next;
                pre->next = curr;
            } else {
                pre = pre->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
// @lc code=end

