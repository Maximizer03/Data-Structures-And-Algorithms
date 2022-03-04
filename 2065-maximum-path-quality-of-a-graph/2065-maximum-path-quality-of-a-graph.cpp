class Solution {
public:
	void dfs(int v, vector<int>&values, vector<vector<pair<int, int>>>&graph, int maxTime, int score, int time, int &res, vector<int>&vis ) {
		if (time > maxTime) {
			return;
		}
		if (vis[v] == 0) {
			score += values[v];
		}
		if (v == 0) {
			res = max(res, score);
		}
		vis[v]++;
		// backtrack soln works because path length cannot be more than 10 with each nodes having max of 4 vertices   4^10
		for (auto &[u, t] : graph[v]) {
			dfs(u, values, graph, maxTime, score, time + t, res, vis);
		}

		vis[v]--;
	}
	int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
		int n = values.size();
		vector<vector<pair<int, int>>>graph(n);
		for (auto &vec : edges) {
			int u = vec[0];
			int v = vec[1];
			int t = vec[2];
			graph[u].push_back({v, t});
			graph[v].push_back({u, t});
		}
		int res = values[0];
		vector<int>vis(n, 0);
		dfs(0, values, graph, maxTime, 0, 0, res, vis);
		return res;
	}
};