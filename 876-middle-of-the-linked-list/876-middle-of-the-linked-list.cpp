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
    ListNode* middleNode(ListNode* head) {
        ListNode *dummy=head;
        int cnt=0;
        while(dummy!=NULL){
            cnt++;
            dummy=dummy->next;
        }
        int tar= (cnt+2)/2;
        cnt=0;
        while(cnt<tar-1){
            cnt++;
            head=head->next;
        }
        return head;
    }
};