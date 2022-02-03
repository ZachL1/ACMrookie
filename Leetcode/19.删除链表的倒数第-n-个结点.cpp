/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针，善后指针始终保持与先驱指针的距离为 n 
        // 当先驱指针到底链表未时，善后指针指向的恰好是倒数第 n 个节点的前一个节点
        ListNode *pioneer = head;
        while (n--) pioneer = pioneer->next;

        if (pioneer == nullptr) { 
            // 要删除的是头节点
            head = head->next;
        }
        else {
            ListNode *latter = head;
            while (pioneer->next) {
                pioneer = pioneer->next;
                latter = latter->next;
            }
            latter->next = latter->next->next;
        }

        return head;
    }
};
// @lc code=end

