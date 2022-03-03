class Solution {
public:
	int z[310][310];
	void dfs(int i, int j, vector<vector<char>>& grid)
	{
		int n = grid.size();
		int m = grid[0].size();

		if (z[i][j])
			return;

		z[i][j] = 1;

		if (i - 1 >= 0 && grid[i - 1][j] == '1')
			dfs(i - 1, j, grid);

		if (i + 1 < n && grid[i + 1][j] == '1')
			dfs(i + 1, j, grid);

		if (j - 1 >= 0 && grid[i][j - 1] == '1')
			dfs(i, j - 1, grid);

		if (j + 1 < m && grid[i][j + 1] == '1')
			dfs(i, j + 1, grid);


	}
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		memset(z, 0, sizeof(z));
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '0')
					continue;
				else
				{
					if (z[i][j] == 1)
						continue;
					else
					{
						cnt++;
						dfs(i, j, grid);
					}
				}
			}
		}
		return cnt;
	}
};