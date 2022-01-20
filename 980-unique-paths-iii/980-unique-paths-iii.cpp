class Solution {
public:
     vector<int>xx, yy;
     int ans; // number of paths
     void dfs(int i, int j, int cnt, vector<vector<int>>&grid, vector<vector<bool>>&vis) {
          int n = grid.size(), m = grid[0].size();
          if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == -1 || vis[i][j] == 1) {
               return;
          }
          if (grid[i][j] == 2) {
               if (cnt == 0) {
                    ans++;
               }
               return;
          }
          vis[i][j] = 1;
          if (grid[i][j] == 0) {
               cnt--;
          }
          for (int k = 0; k < 4; k++) {
               int x = xx[k] + i;
               int y = yy[k] + j;
               dfs(x, y, cnt, grid, vis);
          }
          // backtrack step
          vis[i][j] = 0;
     }
     int uniquePathsIII(vector<vector<int>>& grid) {
          int n = grid.size(), m = grid[0].size(), x, y, cnt = 0;
          vector<vector<bool>>vis(n, vector<bool>(m, 0));
          for (int i = 0; i < n; i++) {
               for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                         x = i; y = j;
                    }
                    else if (grid[i][j] == 0) {
                         cnt++;
                    }
               }
          }
          xx = {0, 0, 1, -1};
          yy = { -1, 1, 0, 0};
          ans = 0;
          dfs(x, y, cnt, grid, vis);
          return ans;
     }
};