class Solution {
private :
     int n, m;
     vector<vector<int>>dp,dp2;
public:
     int query(int r1, int c1, int r2, int c2) {
          r1++; r2++; c1++; c2++;
          int ans = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
          return ans;
     }
     int query2(int r1, int c1, int r2, int c2) {
          r1++; r2++; c1++; c2++;
          int ans = dp2[r2][c2] - dp2[r1 - 1][c2] - dp2[r2][c1 - 1] + dp2[r1 - 1][c1 - 1];
          return ans;
     }
     bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
          n = grid.size(), m = grid[0].size();
          dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
          dp2 = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
          for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= m; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i - 1][j - 1];
               }
          }
          vector<vector<int>> a(n, vector<int>(m, 0));
          for (int i = 0; i < n; i++) {
               for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 0 && i + h - 1 < n && j + w - 1 < m && query(i, j, i + h - 1, j + w - 1) == 0) {
                         a[i + h - 1][j + w - 1] = 1;
                    }
               }
          }
          for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= m; j++) {
                    dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1] + a[i - 1][j - 1];
               }
          }
          for (int i = 0; i < n; i++) {
               for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 0) {
                         int sum= query2(i,j,min(i+h-1,n-1),min(j+w-1,m-1));
                        if(sum==0){
                            return 0;
                        }
                    }
               }
          }
          return 1;
     }
};