class UnionFind {
private:
	vector<int>parent, rank;
public:
	UnionFind(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			rank[i] = 0;
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
	void reset(int v) {
		parent[v] = v;
	}
};
class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>>& A, int f) {
		int m = A.size();
		UnionFind uf(n);
		uf.union_sets(0, f);
		sort(A.begin(), A.end(), [](auto & a, auto & b) {return a[2] < b[2];});
		vector<int>cur;
		for (int i = 0; i < m; i++) {
			int t = A[i][2];
			int j = i;
			while (j < m && A[j][2] == t ) {
				j++;
			}
			cur.clear();
			for (int k = i; k < j; k++) {
				int u = A[k][0];
				int v = A[k][1];
				cur.push_back(u);
				cur.push_back(v);
				uf.union_sets(u, v);
			}
			for (int k = 0; k < cur.size(); k++) {
				if (uf.find_set(cur[k]) != uf.find_set(0)) {
					uf.reset(cur[k]);
				}
			}
			i = j - 1;
		}
		vector<int>ans;
		for (int i = 0; i < n; i++) {
			if (uf.find_set(i) == uf.find_set(0)) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};