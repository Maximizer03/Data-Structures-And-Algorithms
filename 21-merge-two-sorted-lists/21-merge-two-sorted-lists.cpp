
class Solution {
public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
          // Time Complexity : O(n+m)
          // Space Complexity : O(1)
          ListNode dummy(0);
          ListNode *last = &dummy;
          while (l1 && l2) {
               if (l1->val <= l2->val) {
                    last->next = l1;
                    last = last->next;
                    l1 = l1->next;
               }
               else {
                    last->next = l2;
                    last = last->next;
                    l2 = l2->next;
               }
          }
          if (l1) {
               last->next = l1;
          }
          if (l2) {
               last->next = l2;
          }
          return dummy.next;
     }
};