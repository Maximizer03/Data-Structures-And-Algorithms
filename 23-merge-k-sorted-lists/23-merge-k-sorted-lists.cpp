// Iterative Merge Sort Solution
// Time Complexity : O(nlogk)
// Space Complexity : O(1)

class Solution {
public:
     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
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
     ListNode* mergeKLists(vector<ListNode*>& lists) {
          int n = lists.size();
          if (n == 0) {
               return NULL;
          }
          while (n > 1) {
               for (int i = 0; i < n / 2; i++) {
                    lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
               }
               n = (n + 1) / 2;
          }
          return lists.front();
     }
};