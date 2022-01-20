class Solution {
public:
     long long dp[55][104][55];
     long long mod;
     long long calc(int i, int prev_max, int cnt, int n, int m, int k) {
          if (i == n) {
               if (cnt == k) {
                    return 1;
               }
               else {
                    return 0;
               }
          }
          if (dp[i][prev_max][cnt] != -1) {
               return dp[i][prev_max][cnt];
          }
          long long ans = 0;
          for (int j = 1; j <= m; j++) {
               if (j > prev_max) {
                    ans = (ans % mod + calc(i + 1, j, cnt + 1, n, m, k) % mod) % mod;
               }
               else {
                    ans = (ans % mod + calc(i + 1, prev_max, cnt, n, m, k) % mod) % mod;
               }
          }
          return dp[i][prev_max][cnt] = ans;
     }
     int numOfArrays(int n, int m, int k) {
          mod = 1e9 + 7;
          memset(dp, -1, sizeof(dp));
          return calc(0, 0, 0, n, m, k);
     }
};