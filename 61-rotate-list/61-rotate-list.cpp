class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) {
			return head;
		}
		int len = 1;
		ListNode *node = head;
		while (node->next != NULL) {
			node = node->next;
			len++;
		}
		k = k % len;
		if (k == 0) {
			return head;
		}
		k = len - k;
		int cnt = 1;
		ListNode *cur = head;
		while (cnt != k) {
			cnt++;
			cur = cur->next;
		}
		ListNode *start = cur->next;
		cur->next = NULL;
		node->next = head;
		return start;
	}
};