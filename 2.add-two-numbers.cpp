/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.14%)
 * Likes:    7063
 * Dislikes: 1834
 * Total Accepted:    1.2M
 * Total Submissions: 3.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if (!l1) return l2;
      if (!l2) return l1;

      ListNode* head = new ListNode(0);
      ListNode* temp = head;
      int carry = 0, sum = 0;

      while (l1 || l2 || carry) {
        if (l1) {
          sum += l1->val;
          l1 = l1->next;
        }
        if (l2) {
          sum += l2->val;
          l2 = l2->next;
        }

        if (carry) {
          sum += carry;
          carry = 0;
        }

        carry = sum / 10;
        sum = sum % 10;

        temp->next = new ListNode(sum);
        temp = temp->next;
        sum = 0;
      }

      return head->next;
    }
};
// @lc code=end

