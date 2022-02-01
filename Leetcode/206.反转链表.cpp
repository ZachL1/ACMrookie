/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *pre = head, *cur = pre->next, *next = cur->next;
        head->next = nullptr;
        while (true) {
            cur->next = pre;
            pre = cur;
            cur = next;
            if (!cur) break;
            next = cur->next;
        }
        return pre;
    }
};
// @lc code=end

