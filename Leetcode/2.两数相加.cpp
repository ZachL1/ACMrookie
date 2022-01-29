/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
// ListNode add_node;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        int add = (l1->val + l2->val) / 10;
        ListNode* curr = head;

        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 || l2) {
            int sum = add;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            add = sum / 10;
        }
        if (add) curr->next = new ListNode(add);
        return head;

        // 试图节省内存，在原来链表上修改，其实没有必要
        // int add = 0;
        // ListNode* curr1 = l1, *curr2 = l2;
        // do {
        //     int sum = curr1->val + curr2->val + add;
        //     curr1->val = sum % 10;
        //     add = sum / 10;

        //     if (curr1->next == nullptr) {
        //         curr1->next = curr2->next;
        //         break;
        //     }
        //     if (curr2->next == nullptr) {
        //         curr1 = curr1->next;
        //         break;
        //     }

        //     curr1 = curr1->next;
        //     curr2 = curr2->next;
        // } while(true);
        // while (add && curr1) {
        //     int sum = curr1->val + add;
        //     curr1->val = sum % 10;
        //     add = sum / 10;
        //     if (add && curr1->next == nullptr) {
        //         curr1->next = new ListNode(add);
        //         break;
        //     }
        //     curr1 = curr1->next;
        // }
        // return l1;
    }
};
// @lc code=end

