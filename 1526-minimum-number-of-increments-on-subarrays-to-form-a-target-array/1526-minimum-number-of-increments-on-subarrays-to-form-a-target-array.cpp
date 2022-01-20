class Solution {
public:
     int minNumberOperations(vector<int>& h) {
          // dp[i]=> min no of moves to build the blocks till i
          int n = h.size();
          vector<int>dp(n);
          dp[0] = h[0];
          for (int i = 1; i < n; i++) {
               if (h[i] <= h[i - 1]) {
                    dp[i] = dp[i - 1];
               }
               else {
                    dp[i] = dp[i - 1] + (h[i] - h[i - 1]);
               }
          }
          return dp[n - 1];
     }
};