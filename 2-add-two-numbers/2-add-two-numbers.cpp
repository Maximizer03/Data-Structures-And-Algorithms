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
    int count(ListNode *p){
        int cnt=0;
        ListNode *st=p;
        while(st){
            st=st->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* addTwoNumbers(ListNode* f, ListNode* s) {
        if(count(f)<count(s)){
            ListNode *temp=f;
            f=s;
            s=temp;
        }
        ListNode *head=f;
        int car=0;
        while(s){
            f->val+= s->val+car;
            car= f->val/10;
            f->val%=10;
            if(f->next==NULL && car>0){
                ListNode * last= new ListNode(car);
                f->next=last;
                car=0;
                break;
            }
            f=f->next;
            s=s->next;
        }
        while(f){
            f->val+= car;
            car= f->val/10;
            f->val%=10;
            if(f->next==NULL && car>0){
                ListNode * last= new ListNode(car);
                f->next=last;
                car=0;
                break;
            }
            f=f->next;
        }
        return head;
        
        
    }
};