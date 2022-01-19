class NumMatrix {
private:
     int n, m;
     vector<vector<int>>dp;
public:
     NumMatrix(vector<vector<int>>& matrix) {
          n = matrix.size(), m = matrix[0].size();
          dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
          // dp[i+1][j+1]=> sum of the matrix from [0,0] to [i,j]
          for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= m; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
               }
          }
     }

     int sumRegion(int r1, int c1, int r2, int c2) {
          r1++; c1++; r2++; c2++;
          int ans = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
          return ans;
     }
};