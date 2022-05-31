class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *d = new ListNode(0);
		d->next = head;
		ListNode *rt = d;
		ListNode *c = d;
		ListNode *p = d;
		while (rt->next != NULL && rt->next->next != NULL) {
			p = rt->next;
			c = rt->next->next;
			p->next = c->next;
			c->next = p;
			rt->next = c;
			rt = rt->next->next;
		}
		return d->next;
	}
};