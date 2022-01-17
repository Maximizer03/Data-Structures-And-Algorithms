// dp solution
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
     int longestValidParentheses(string s) {
          int n = s.size();
          vector<int>dp(n, 0);
          // dp[i]=> length of the longest valid substring ending at i
          int mx = 0;
          for (int i = 0; i < n; i++) {
               if (s[i] == ')') {
                    // valid only when s[i] ends with closing bracket else dp[i]=0
                    if (i - 1 >= 0) {
                         if (s[i - 1] == ')') {
                              if (i - dp[i - 1] - 1 >= 0) {
                                   if (s[i - dp[i - 1] - 1] == '(') {
                                        dp[i] = 2 + dp[i - 1];
                                        if (i - dp[i - 1] - 2 >= 0) {
                                             dp[i] += dp[i - dp[i - 1] - 2];
                                        }
                                   }
                              }
                         }
                         else {
                              dp[i] = 2;
                              if (i - 2 >= 0) {
                                   dp[i] += dp[i - 2];
                              }
                         }
                    }
               }
               mx = max(mx, dp[i]);
          }
          return mx;
     }
};
