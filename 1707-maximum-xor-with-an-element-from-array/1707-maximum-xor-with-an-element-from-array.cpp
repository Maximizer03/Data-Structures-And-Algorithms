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
	vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		vector<int>ans(queries.size());
		vector<pair<int, pair<int, int>>>q;
		for (int i = 0; i < queries.size(); i++) {
			int x = queries[i][0];
			int m = queries[i][1];
			q.push_back({m, {x, i}});
		}
		Trie *trie = new Trie();
		sort(begin(q), end(q));
		sort(begin(nums), end(nums));
		int j = 0;
		for (int i = 0; i < q.size(); i++) {
			int m = q[i].first;
			int x = q[i].second.first;
			int ind = q[i].second.second;
			while (j < n && nums[j] <= m) {
				trie->insert(nums[j]);
				j++;
			}
			if (j != 0) {
				int mx = trie->findMax(x);
				ans[ind] = mx;
			}
			else {
				ans[ind] = -1;
			}
		}
		return ans;
	}
};