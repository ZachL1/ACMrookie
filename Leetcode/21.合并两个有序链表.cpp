/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head(-1, list1);
        ListNode *curr = &head, *other = list2, *temp;

        while (curr && other) {
            while (curr->next && curr->next->val <= other->val) curr = curr->next;
            temp = other;
            other = curr->next;
            curr->next = temp;
        }

        return head.next;
    }
};
// @lc code=end

