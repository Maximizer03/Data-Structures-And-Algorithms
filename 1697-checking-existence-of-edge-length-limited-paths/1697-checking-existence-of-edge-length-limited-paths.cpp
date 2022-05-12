class Solution {
	struct DSU {
		vector<int>parent, rank;
		void init(int n) {
			parent.resize(n + 1);
			rank.resize(n + 1);
			for (int v = 0; v <= n; v++) {
				parent[v] = v;
				rank[v] = 0;
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
	};

public:
	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& Q) {
		priority_queue<array<int, 3> , vector<array<int, 3>>, greater<array<int, 3>> >q;
		for (int i = 0; i < e.size(); i++) {
			int u = e[i][0], v = e[i][1], w = e[i][2];
			q.push({w, u, v});
		}
		vector<vector<pair<int, int>>>g(n);
		vector<array<int, 3>>edges;
		DSU f;
		f.init(n + 1);
		while (!q.empty()) {
			array<int, 3>a = q.top();
			q.pop();
			int u = a[1], v = a[2], w = a[0];
			if (f.find_set(u) != f.find_set(v)) {
				f.union_sets(u, v);
				edges.push_back({w, u, v});
				g[u].push_back({v, w});
				g[v].push_back({u, w});
			}
		}
		vector<bool>ans(Q.size(), false);

		vector<array<int, 4>>vec;
		for (int i = 0; i < Q.size(); i++) {
			int u = Q[i][0], v = Q[i][1], W = Q[i][2], ind = i;
			array<int, 4>k = {W, u, v, ind};
			vec.push_back(k);
		}
		sort(begin(vec), end(vec));
		sort(begin(edges), end(edges));
		DSU f2;
		f2.init(n + 1);
		int j = 0;
		// edge 0-> weight, 1->u 2->v
		// vec 0-> weigth 1-> u 2->v 3-> ind of query
		for (int i = 0; i < vec.size(); i++) {
			while (j < edges.size() && edges[j][0] < vec[i][0]) {
				int u = edges[j][1], v = edges[j][2];
				f2.union_sets(u, v);
				j++;
			}
			int u = vec[i][1], v = vec[i][2];
			if (f2.find_set(u) == f2.find_set(v)) {
				ans[vec[i][3]] = true;
			}
		}
		return ans;
	}
};