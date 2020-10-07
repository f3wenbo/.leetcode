/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (38.00%)
 * Likes:    2125
 * Dislikes: 106
 * Total Accepted:    231.9K
 * Total Submissions: 589K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
  ListNode *sortList(ListNode *head) {
    if(!head || !(head->next)) return head;

    ListNode* cur = head;
    int length = 0;
    while(cur){
      length++;
      cur = cur->next;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode *left, *right, *tail;
    for(int step = 1; step < length; step *= 2){
      cur = dummy.next;
      tail = &dummy;
      while(cur){
        left = cur;
        right = split(left, step);
        cur = split(right,step);
        tail = merge(left, right, tail);
      }
    }
    return dummy.next;
  }
private:
  ListNode* split(ListNode *head, int n){
    for(int i = 1; head && i < n; i++) head = head->next;
    
    if(!head) return NULL;
    ListNode *second = head->next;
    head->next = NULL;
    return second;
  }

  ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
    ListNode *cur = head;
    while(l1 && l2){
      if(l1->val > l2->val){
        cur->next = l2;
        cur = l2;
        l2 = l2->next;
      } else {
        cur->next = l1;
        cur = l1;
        l1 = l1->next;
      }
    }
    cur->next = (l1 ? l1 : l2);
    while(cur->next) cur = cur->next;
    return cur;
  }
};
// @lc code=end

