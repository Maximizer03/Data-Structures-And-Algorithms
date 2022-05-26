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
};

class Trie {
private:
	Node *root;
public:
	Trie() {
		root = new Node();
	}
	void insert(int num, int d) {
		Node *node = root;
		for (int i = 20; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (!node->containsKey(bit)) {
				node->put(bit, new Node());
			}
			node = node->get(bit);
			node->cnt += d;
		}
	}
	int findMax(int num) {
		int ans = 0;
		Node *node = root;
		for (int i = 20; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (node->containsKey(1 - bit) && node->links[1 - bit]->cnt > 0 ) {
				ans = ans | (1 << i);
				node = node->get(1 - bit);
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
	vector<int> maxGeneticDifference(vector<int>& p, vector<vector<int>>& q) {
		int m = q.size();
		vector<int>ans(q.size());
		map<int, vector<pair<int, int>> > mp;
		for (int i = 0; i < m; i++) {
			int v = q[i][0];
			int num = q[i][1];
			mp[v].push_back({num, i});
		}
		Trie *trie = new Trie();
		int n = p.size();
		vector<vector<int>>g(n);
		int rt = -1;
		for (int i = 0; i < n; i++) {
			if (p[i] == -1) {
				rt = i;
			}
			else {
				g[i].push_back(p[i]);
				g[p[i]].push_back(i);
			}
		}
		function<void(int, int)>dfs = [&](int v, int par) {
			trie->insert(v, 1);
			if (mp.count(v)) {
				for (auto &x : mp[v]) {
					int i = x.second;
					int val = x.first;
					ans[i] = trie->findMax(val);
				}
			}
			for (auto &u : g[v]) {
				if (u != par) {
					dfs(u, v);
				}
			}
			trie->insert(v, -1);
		};
		dfs(rt, -1);
		return ans;
	}
};