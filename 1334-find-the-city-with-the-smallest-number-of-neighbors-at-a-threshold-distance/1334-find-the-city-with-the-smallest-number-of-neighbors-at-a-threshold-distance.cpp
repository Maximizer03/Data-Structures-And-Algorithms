class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<int>>dp = getShortestDistances(n, edges);
		// dp[i][j]=> shortest distance path starting from i to j
		vector<int>cnt(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && dp[i][j] <= distanceThreshold ) {
					cnt[i]++;
				}
			}
		}
		int mn = INT_MAX, city = -1;
		for (int i = 0; i < n; i++) {
			if (cnt[i] < mn) {
				mn = cnt[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (cnt[i] == mn) {
				city = max(city, i);
			}
		}
		return city;

	}
private:
	vector<vector<int>> getShortestDistances(int n, vector<vector<int>>&edges) {
		vector<vector<int>>dist = vector<vector<int>>(n, vector<int>(n, INT_MAX));
		for (int i = 0; i < n; i++) {
			dist[i][i] = 0;
		}
		for (auto &edge : edges) {
			int start = edge[0], end = edge[1], weight = edge[2];
			dist[start][end] = weight;
			dist[end][start] = weight;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
						continue;
					}
					else {
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}
		return dist;
	}
};