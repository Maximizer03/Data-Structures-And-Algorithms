class Solution {
public:
	int ans;
    vector<int>dx = {1, -1, 0, 0};
	vector<int>dy = {0, 0, 1, -1};
	void dfs(int i, int j, int pos, vector<vector<int>>&vis, vector<vector<char>>&board, string &word) {
		if (pos == word.size() - 1) {
			ans = 1;
		}
		int n = board.size(), m = board[0].size();
		
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == word[pos + 1] && vis[nx][ny] == 0) {
				vis[nx][ny] = 1;
				dfs(nx, ny, pos + 1, vis, board, word);
				vis[nx][ny] = 0;
			}
		}
	}
	bool exist(vector<vector<char>>& board, string word) {
		ans = 0;
		int n = board.size(), m = board[0].size();
		vector<vector<int>>vis(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == word[0]) {
					vis[i][j] = 1;
					dfs(i, j, 0, vis, board, word);
					vis[i][j] = 0;
				}
			}
		}
		return (ans > 0);
	}
};