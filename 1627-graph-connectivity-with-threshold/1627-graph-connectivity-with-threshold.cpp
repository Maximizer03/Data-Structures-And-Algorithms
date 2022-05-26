class Solution {
	vector<int>parent, rank;
public:
	void init(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1);
		for (int v = 0; v <= n; v++) {
			parent[v] = v;
		}
	}
	int find_set(int v) {
		if (v == parent[v]) {
			return v;
		}
		return parent[v] = find_set(parent[v]);
	}
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			parent[b] = a;
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
		}
	}
	vector<bool> areConnected(int n, int t, vector<vector<int>>& q) {
		int m = q.size();
		init(n + 1);
		vector<bool>ans(m);
		for (int i = t + 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				union_sets(i, j);
			}
		}
		for (int i = 0; i < m; i++) {
			int u = q[i][0], v = q[i][1];
			if (find_set(u) == find_set(v)) {
				ans[i] = true;
			}
		}
		return ans;
	}
};