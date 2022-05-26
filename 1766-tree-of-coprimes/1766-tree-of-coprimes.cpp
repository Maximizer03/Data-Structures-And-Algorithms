class Solution {
public:
	int gcd[55][55];
	void dfs(int v, int par, int dep, vector<vector<int>>&g, vector<int>&ans, vector<pair<int, int>>&p, vector<int>&a) {
		vector<array<int, 3>>c;
		int mx = 0, nd = -1;
		for (int i = 1; i <= 50; i++) {
			if (p[i].first > 0) {
				int g = gcd[a[v]][i];
				if (g == 1) {
					if (p[i].first > mx) {
						mx = p[i].first;
						nd = p[i].second;
					}
				}
			}
		}
		if (mx > 0) {
			ans[v] = nd;
		}
		pair<int, int>org = p[a[v]];
		p[a[v]] = {dep, v};
		for (auto &u : g[v]) {
			if (u != par) {
				int dd = dep + 1;
				dfs(u, v, dd, g, ans, p, a);
			}
		}
		p[a[v]] = org;
	}
	vector<int> getCoprimes(vector<int>& a, vector<vector<int>>& e) {
		int n = a.size();
		vector<vector<int>>g(n);
		for (int i = 0; i < n - 1; i++) {
			int u = e[i][0], v = e[i][1];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				gcd[i][j] = __gcd(i, j);
			}
		}
		vector<pair<int, int>>p(52);
		vector<int>ans(n, -1);
		dfs(0, -1, 1, g, ans, p, a);
		return ans;
	}
};