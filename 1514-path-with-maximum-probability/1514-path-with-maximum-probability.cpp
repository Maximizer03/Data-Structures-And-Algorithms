class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		vector<double>p(n, 0.0000000);
		p[start] = 1.00000;
		vector<pair<int, double>>g[n];
		int m = edges.size();
		for (int i = 0; i < m; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			double pr = succProb[i];
			g[u].push_back({v, pr});
			g[v].push_back({u, pr});
		}
		using pdi = pair<double, int>;
		priority_queue<pdi, vector<pdi>>q;
		// queue entry will be of the form (max prob,node)
		q.push({1.0000, start});
		while (!q.empty()) {
			int cur_node = q.top().second;
			double cur_prob = q.top().first;
			q.pop();
			for (auto &x : g[cur_node]) {
				int next_node = x.first;
				double weight = x.second;
				if (p[next_node] < weight * p[cur_node]) {
					p[next_node] = weight * p[cur_node];
					q.push({p[next_node], next_node});
				}
			}
		}
		return p[end];
	}
};