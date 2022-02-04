/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int mini = 0;
        ListNode head(0, lists[0]);
        ListNode *curr = &head;

        // while (true) {
        //     // 每次都找所有链表中头最小的那个，接到curr的下一节点
        //     for (int i = 0; i < lists.size(); ++i) {
        //         if (!lists[mini] || (lists[i] && lists[i]->val < lists[mini]->val)) mini = i;
        //     }
        //     if (!lists[mini]) break;
        //     curr->next = lists[mini];
        //     curr = curr->next;
        //     lists[mini] = lists[mini]->next;
        // }

        // 每次都遍历所有链表，复杂度高 O(k*n) ，n 为所有链表总节点数
        // 改用优先队列来实现，插入和删除的复杂度为 logk，总的复杂度降为 O(logk*n)
        auto cmp = [](ListNode* left, ListNode* right) { return left->val > right->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (ListNode* &list : lists) 
            if(list) q.push(list);

        while (!q.empty()) {
            ListNode *min_list = q.top(); q.pop();
            curr->next = min_list;
            curr = curr->next;
            if(min_list->next) q.push(min_list->next);
        }

        return head.next;
    }
};
// @lc code=end

