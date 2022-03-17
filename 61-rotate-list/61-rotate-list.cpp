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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int s=0;
        ListNode *node=head;
        while(node!=NULL){
            node= node->next;
            s++;
        }
        
        k= k%s;
        if(k==0){
            return head;
        }
        k=s-k;
        int cnt=1;
        ListNode *cur=head;
        while(cnt!=k){
            cnt++;
            cur=cur->next;
        }
        ListNode *start=cur->next;
        cur->next=NULL;
        ListNode *dummy=start;
        while(dummy->next!=NULL){
            dummy=dummy->next;
        }
        dummy->next=head;
        return start;
    }
};