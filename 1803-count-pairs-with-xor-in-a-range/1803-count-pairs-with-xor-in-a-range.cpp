struct Node {
	Node *links[2];
	int cnt = 0;
	bool containsKey(int bit) {
		return (links[bit] != NULL);
	}
	void put(int bit, Node *node) {
		links[bit] = node;
	}
	Node *get(int bit) {
		return links[bit];
	}
	int getCount(Node *node) {
		return node->cnt;
	}
};

class Trie {
private:
	Node *root;
public:
	Trie() {
		root = new Node();
	}
	void insert(int num) {
		Node *node = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (!node->containsKey(bit)) {
				node->put(bit, new Node());
			}
			node = node->get(bit);
			node->cnt++;
		}
	}
	int calc(int x, int k) {
		int ans = 0;
		Node *node = root;
		for (int i = 31; i >= 0; i--) {
			int b1 = (x >> i) & 1;
			int b2 = (k >> i) & 1;
			if (b1 == 1 && b2 == 1) {
				if (node->containsKey(1)) {
					ans += node->getCount(node->get(1));
				}
				if (node->containsKey(0)) {
					node = node->get(0);
				}
				else {
					break;
				}
			}
			else if (b1 == 0 && b2 == 1) {
				if (node->containsKey(0)) {
					ans += node->getCount(node->get(0));
				}
				if (node->containsKey(1)) {
					node = node->get(1);
				}
				else {
					break;
				}
			}
			else if (b1 == 1 && b2 == 0) {
				if (node->containsKey(1)) {
					node = node->get(1);
				}
				else {
					break;
				}
			}
			else {
				if (node->containsKey(0)) {
					node = node->get(0);
				}
				else {
					break;
				}
			}
		}
		return ans;
	}
};
class Solution {
public:
	int countPairs(vector<int>& nums, int low, int high) {
		Trie *trie = new Trie();
		int n = nums.size();
		if (n == 1) {
			return 0;
		}
		trie->insert(nums[0]);
		int ans = 0;
		for (int i = 1; i < n; i++) {
			ans +=  trie->calc(nums[i], high + 1) - trie->calc(nums[i], low) ;
			trie->insert(nums[i]);
		}
		return ans;
	}
};