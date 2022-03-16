class Solution {
	// DSU code
private:
	vector<int>parent, rank;
	vector<int>spf;
public:
	void init(int n) {
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
			parent[b] = a;
			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
		}
	}
	void sieve(int n) {
		spf.resize(n);
		for (int i = 2; i < n; i++) {
			spf[i] = i;
		}
		for (int i = 2; i * i < n; i++) {
			if (spf[i] == i) {
				for (int j = i * i; j < n; j += i) {
					if (spf[j] > i) {
						spf[j] = i;
					}
				}
			}
		}
	}

	vector<int>fact(int n) {
		vector<int>v;
		while (n > 1) {
			v.push_back(spf[n]);
			n /= spf[n];
		}
		return v;
	}

	// DSU code
	bool gcdSort(vector<int>& nums) {
		int n = nums.size();
		int mx = *max_element(begin(nums), end(nums));
		init(mx + 1);
		sieve(mx + 1);
		for (int i = 0; i < n; i++) {
			int x = nums[i];
			vector<int>v = fact(x);
			for (auto &y : v) {
				union_sets(x, y);
			}
		}
		vector<int>a = nums;
		sort(begin(a), end(a));
		for (int i = 0; i < n; i++) {
			if (find_set(a[i]) != find_set(nums[i])) {
				return false;
			}
		}
		return true;
	}
};