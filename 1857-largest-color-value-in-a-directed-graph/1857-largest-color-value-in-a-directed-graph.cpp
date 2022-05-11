class Solution {
public:
	int largestPathValue(string s, vector<vector<int>>&e) {
		int n = s.size();
		vector<int>indegree(n, 0);
		vector<vector<int>>g(n);
		for (int i = 0; i < e.size(); i++) {
			int u = e[i][0], v = e[i][1];
			g[u].push_back(v);
			indegree[v]++;
		}
		queue<int>q;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int>t;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			cnt++;
			t.push_back(v);
			for (auto &u : g[v]) {
				indegree[u]--;
				if (indegree[u] == 0) {
					q.push(u);
				}
			}
		}
		if (cnt < n) {
			return -1;
		}
		vector<vector<int>>f(n, vector<int>(26, 0));
		for (int i = 0; i < n; i++) {
			int let = s[i] - 'a';
			f[i][let]++;
		}
		vector<vector<int>>dp(n, vector<int>(26, 0));
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int v = t[i];
			for (int j = 0; j < 26; j++) {
				dp[v][j] += f[v][j];
			}
			for (auto &u : g[v]) {
				for (int j = 0; j < 26; j++) {
					dp[u][j] = max(dp[u][j], dp[v][j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				mx = max(mx, dp[i][j]);
			}
		}
		return mx;
	}
};