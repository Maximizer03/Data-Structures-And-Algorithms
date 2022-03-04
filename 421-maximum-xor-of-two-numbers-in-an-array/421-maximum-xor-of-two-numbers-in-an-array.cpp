struct Node {
	Node *links[2];
	bool containsKey(int bit) {
		return (links[bit] != NULL);
	}
	void put(int bit, Node * node) {
		links[bit] = node;
	}
	Node *get(int bit) {
		return links[bit];
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
		}
	}
	int findMax(int num) {
		int ans = 0;
		Node *node = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (node->containsKey(!bit)) {
				ans = ans | (1 << i);
				node = node->get(!bit);
			}
			else {
				node = node->get(bit);
			}
		}
		return ans;
	}
};
class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int n = nums.size();
		Trie *trie= new Trie();
		for (int i = 0; i < n; i++) {
			trie->insert(nums[i]);
		}
		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, trie->findMax(nums[i]));
		}
		return mx;
	}
};