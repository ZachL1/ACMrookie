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
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode *head, *start, *end;
        if(list1->val < list2->val) head = list1;
        else head = list2;

        while (list1 && list2) {
            // if (list1) {
                start = list1;
                while (list1 && (list1->val < list2->val)) {
                    end = list1;
                    list1 = list1->next;
                }
                end->next = list2->next;
                list2->next = start;
                if (!list1) break;

            // } else {
                start = list2;
                while (list2 && (list1->val >= list2->val)) {
                    end = list2;
                    list2 = list2->next;
                }
                end->next = list1->next;
                list1->next = start;
            // }
        }
        return head;
    }
};
// @lc code=end

