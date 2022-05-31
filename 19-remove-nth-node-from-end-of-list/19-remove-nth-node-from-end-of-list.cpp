class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) {
			return head;
		}
		ListNode * dummy = new ListNode(0);
		dummy->next = head;
		ListNode *right = head;
		while (n != 0) {
			right = right->next;
			n--;
		}
		ListNode *left = dummy;
		while (right != NULL) {
			right = right->next;
			left = left->next;
		}
		left->next = left->next->next;
		return dummy->next;
	}
};