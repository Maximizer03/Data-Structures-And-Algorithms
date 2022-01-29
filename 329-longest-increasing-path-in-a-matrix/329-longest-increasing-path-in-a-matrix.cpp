class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		vector<vector<int>>g = graph(matrix);
		int n = (matrix.size()) * (matrix[0].size());
		// n is total number of nodes in the graph (DAG)
		vector<int>indegree(n, 0);
		for (int i = 0; i < n; i++) {
			for (auto &x : g[i]) {
				indegree[x]++;
			}
		}
		queue<int>q;
		vector<int>dp(n, 0);
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				dp[i] = 1;
			}
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto &u : g[v]) {
				dp[u] = max(dp[u], dp[v] + 1);
				indegree[u]--;
				if (indegree[u] == 0) {
					q.push(u);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());

	}
private:
	bool isValid(int x, int y, int n, int m) {
		return (x >= 0 && x < n && y >= 0 && y < m);
	}
	int getVal(int i, int j, int n, int m) {
		int ans = i * m + j;
		return ans;
	}
	vector<vector<int>>graph(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>>g(n * m);
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					int new_x = i + dx[k];
					int new_y = j + dy[k];
					if (isValid(new_x, new_y, n, m) && matrix[i][j] < matrix[new_x][new_y]) {
						int start = getVal(i, j, n, m);
						int end = getVal(new_x, new_y, n, m);
						g[start].push_back(end);
					}
				}
			}
		}
		return g;
	}
};