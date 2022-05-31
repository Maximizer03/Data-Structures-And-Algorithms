class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>ans(n, vector<int>(n));
		int j = 2, d = 0;
		vector<int>dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
		ans[0][0] = 1;
		int x = 0, y = 0;
		int nx = 0, ny = 1;
		while (j <= n * n) {
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && ans[nx][ny] == 0) {
				ans[nx][ny] = j;
				x = nx, y = ny;
				nx = x + dx[d];
				ny = y + dy[d];
				j++;
			}
			d = (d + 1) % 4;
			nx = x + dx[d], ny = y + dy[d];
		}
		return ans;
	}
};