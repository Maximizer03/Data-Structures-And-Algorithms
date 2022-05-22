class Solution {
private:
	vector<int>parent, rank;
public:
	void init(int n) {
		parent.resize(n + 1, 0);
		rank.resize(n + 1, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
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
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
			parent[b] = a;
		}
	}
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int n = s.size();
		init(n + 1);
		for (auto  &p : pairs) {
			int x = p[0], y = p[1];
			union_sets(x, y);
		}
		map<int, vector<int> >m;
		for (int i = 0; i < n; i++) {
			int st = find_set(i);
			m[st].push_back(i);
		}
		for (auto &x : m) {
			string t = "";
			vector<int>v = x.second;
			for (auto &x : v) {
				t += s[x];
			}
			sort(begin(t), end(t));
			int cnt = 0;
			for (auto &x : v) {
				s[x] = t[cnt];
				cnt++;
			}
		}
		return s;
	}
};