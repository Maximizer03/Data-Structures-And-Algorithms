class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int>>> g = buildGraph(times, n);
		vector<int> dist = shortestDistance(g, n, k);
		int max_time = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INT_MAX) {
				return -1;
			}
			max_time = max(max_time, dist[i]);
		}
		return max_time;
	}
private:
	vector<vector<pair<int, int>>> buildGraph(vector<vector<int>>& times, int n) {
		vector<vector<pair<int, int>>> graph(n + 1);
		for (auto &edge : times) {
			int start = edge[0];
			int end = edge[1];
			int weight = edge[2];
			graph[start].push_back({end, weight});
		}
		return graph;
	}
	vector<int> shortestDistance(vector<vector<pair<int, int>>>&g, int n, int src) {
		vector<int>dist(n + 1, INT_MAX);
		dist[src] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>q;
		// Entry of pq will be of the form (dist,node)
		q.push({0, src});
		while (!q.empty()) {
			int cur_node = q.top().second;
			int d = q.top().first;
			q.pop();
			for (auto &node : g[cur_node]) {
				int next_node = node.first;
				int weight = node.second;
				if (dist[cur_node] + weight < dist[next_node]) {
					dist[next_node] = dist[cur_node] + weight;
					q.push({dist[next_node], next_node});
				}
			}
		}
		return dist;
	}
};