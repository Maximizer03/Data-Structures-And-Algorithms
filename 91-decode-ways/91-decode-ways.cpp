class Solution {
public:
     int numDecodings(string s) {
          int n = s.size();
          if (s[0] == '0') {
               return 0;
          }
          vector<int>dp(n + 1, 0);
          dp[0] = dp[1] = 1;
          for (int i = 2; i <= n; i++) {
               int n1 = s[i - 1] - '0';
               if (n1 > 0) {
                    dp[i] += dp[i - 1];
               }
               int n2 = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
               if (n2 >= 10 && n2 <= 26) {
                    dp[i] += dp[i - 2];
               }
          }
          return dp[n];
     }
};