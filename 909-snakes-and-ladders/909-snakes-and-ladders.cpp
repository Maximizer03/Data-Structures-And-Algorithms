class Solution {
public:
	int snakesAndLadders(vector<vector<int>>& board) {
		int n = board.size();
		vector<vector<int>>m(n, vector<int>(n));
		int cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			int x = (n - 1) - i;
			if (x % 2 == 0) {
				for (int j = 0; j < n; j++) {
					int x = cnt / n;
					int y = cnt % n;
					m[x][y] = board[i][j];
					if (m[x][y] != -1) {
						m[x][y]--;
					}
					cnt++;
				}
			}
			else {
				for (int j = n - 1; j >= 0; j--) {
					int x = cnt / n;
					int y = cnt % n;
					m[x][y] = board[i][j];
					if (m[x][y] != -1) {
						m[x][y]--;
					}
					cnt++;
				}
			}
		}
		vector<int>vis(n * n, 0);
		queue<pair<int, int>>q;
		q.push({0, 0});
		vis[0] = 1;
		while (!q.empty()) {
			int v = q.front().first;
			int moves = q.front().second;
			q.pop();
			if (v == n * n - 1) {
				return moves;
			}
			for (int j = 1; j <= 6; j++) {
				if (v + j >= n * n) {
					continue;
				}
				int x = (v + j) / n;
				int y = (v + j) % n;
				int nxt = m[x][y] == -1 ? v + j : m[x][y];
				if (!vis[nxt]) {
					vis[nxt] = 1;
					q.push({nxt, moves + 1});
				}
			}
		}
		return -1;
	}
};