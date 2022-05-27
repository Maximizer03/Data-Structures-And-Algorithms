class Solution {
public:
	bool isPrintable(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		unordered_map<int, int>xmx, xmn, ymx, ymn;
		unordered_set<int>c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int col = grid[i][j];
				c.insert(col);
				xmx[col] = -1e9;
				xmn[col] = 1e9;
				ymx[col] = -1e9;
				ymn[col] = 1e9;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int col = grid[i][j];
				xmx[col] = max(xmx[col], i);
				xmn[col] = min(xmn[col], i);
				ymx[col] = max(ymx[col], j);
				ymn[col] = min(ymn[col], j);
			}
		}
		vector<set<int>>g(61);
		vector<int>indegree(61, 0);
		for (auto col : c) {
			unordered_set<int>t;
			for (int i = xmn[col]; i <= xmx[col]; i++) {
				for (int j = ymn[col]; j <= ymx[col]; j++) {
					if (grid[i][j] != col) {
						if (t.find(grid[i][j]) == t.end()) {
							indegree[grid[i][j]]++;
							g[col].insert(grid[i][j]);
							t.insert(grid[i][j]);
						}
					}
				}
			}
		}
		queue<int>q;
		for (auto col : c) {
			if (indegree[col] == 0) {
				q.push(col);
			}
		}
		int cnt = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			cnt++;
			for (auto &u : g[v]) {
				indegree[u]--;
				if (indegree[u] == 0) {
					q.push(u);
				}
			}
		}
		return (cnt == c.size());
	}
};