class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		vector<vector<int>>g(n);
		vector<int>indegree(n, 0);
		vector<int>dp(n);
		for (int i = 0; i < n; i++) {
			dp[i] = quiet[i];
		}
		for (int i = 0; i < richer.size(); i++) {
			int u = richer[i][0];
			int v = richer[i][1];
			g[u].push_back(v);
			indegree[v]++;
		}
		map<int, int>m;
		queue<int>q;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int>t;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			t.push_back(v);
			for (auto &u : g[v]) {
				indegree[u]--;
				if (indegree[u] == 0) {
					q.push(u);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			int x = t[i];
			for (auto &u : g[x]) {
				dp[u] = min({dp[u], dp[x]});
			}
		}
		for (int i = 0; i < n; i++) {
			m[quiet[i]] = i;
		}
		vector<int>ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = m[dp[i]];
		}
		return ans;
	}
};