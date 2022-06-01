class Solution {
public:
	bool calc(string &s, string &t) {
		int n = s.size(), m = t.size();
		int j = 0;
		for (int i = 0; i < m && j < n; i++) {
			if (t[i] == s[j]) {
				j++;
			}
		}
		return (j >= n);
	}
	int longestPathinDAG(vector<vector<int>>&g) {
		int n = g.size();
		vector<int>in(n);
		for (int i = 0; i < n; i++) {
			for (auto &x : g[i]) {
				in[x]++;
			}
		}
		queue<int>q;
		vector<int>dp(n, 1);
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto &u : g[v]) {
				dp[u] = max(dp[u], dp[v] + 1);
				in[u]--;
				if (in[u] == 0) {
					q.push(u);
				}
			}
		}
		return *max_element(begin(dp), end(dp));
	}
	int longestStrChain(vector<string>& w) {
		int n = w.size();
		vector<vector<int>>g(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (w[i].size() + 1 == w[j].size()) {
					if (calc(w[i], w[j])) {
						g[i].push_back(j);
					}
				}
			}
		}
		return longestPathinDAG(g);
	}
};