/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (47.00%)
 * Likes:    1750
 * Dislikes: 152
 * Total Accepted:    409K
 * Total Submissions: 848.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;

        while (head && head->next && head->next->next) {
            ListNode* n1 = head->next;
            ListNode* n2 = n1->next;

            n1->next = n2->next;
            n2->next = n1;

            head->next = n2;
            head = n1;
        }
        return dummy.next;
    }
};
// @lc code=end

