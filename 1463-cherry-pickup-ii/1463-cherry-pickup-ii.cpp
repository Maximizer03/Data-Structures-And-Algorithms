class Solution {
public:
     bool isvalid(int j, int m) {
          return (j >= 0 && j < m);
     }
     int dp[75][75][75];
     int calc(int r, int c1, int c2, vector<vector<int>>&grid) {
          int n = grid.size(), m = grid[0].size();
          if (r == n) {
               return 0;
          }
          if (dp[r][c1][c2] != -1) {
               return dp[r][c1][c2];
          }
          int ans = grid[r][c1];
          if (c1 != c2) {
               ans += grid[r][c2];
          }
          int t = ans;
          for (int j = -1; j <= 1; j++) {
               for (int k = -1; k <= 1; k++) {
                    if (isvalid(j + c1, m) && isvalid(k + c2, m)) {
                         ans = max(ans, t + calc(r + 1, j + c1, k + c2, grid));
                    }
               }
          }
          return dp[r][c1][c2] = ans;
     }
     int cherryPickup(vector<vector<int>>& grid) {
          int n = grid.size(), m = grid[0].size();
          memset(dp, -1, sizeof(dp));
          return calc(0, 0, m - 1, grid);
     }
};