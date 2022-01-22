class Solution {
public:
     int minFallingPathSum(vector<vector<int>>& matrix) {
          int n = matrix.size();
          vector<vector<int>>dp(n, vector<int>(n, 1e9));
          for (int i = 0; i < n; i++) {
               dp[0][i] = matrix[0][i];
          }
          for (int i = 1; i < n; i++) {
               for (int j = 0; j < n; j++) {
                    for (int k = j - 1; k <= j + 1; k++) {
                         if (k >= 0 && k < n) {
                              dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][k]);
                         }
                    }
               }
          }
          int mn = 1e9;
          for (int i = 0; i < n; i++) {
               mn = min(mn, dp[n - 1][i]);
          }
          return mn;
     }
};