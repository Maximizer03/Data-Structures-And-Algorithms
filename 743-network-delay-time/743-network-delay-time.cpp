class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<int>>dp = shortestDistance(times, n);
		k--;
		int maxTime = 0;
		for (int i = 0; i < n; i++) {
			if (dp[k][i] == INT_MAX) {
				return -1;
			}
			maxTime = max(maxTime, dp[k][i]);
		}
		return maxTime;
	}
private:
	vector<vector<int>> shortestDistance(vector<vector<int>>&times, int n) {
		vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
		for (int i = 0; i < n; i++) {
			dist[i][i] = 0;
		}
		for (auto &edge : times) {
			int start = edge[0] - 1;
			int end = edge[1] - 1;
			int weight = edge[2];
			dist[start][end] = weight;
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