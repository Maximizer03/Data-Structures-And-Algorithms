class Solution {
public:
     int dp[505][505];
     int calc(vector<int>&a, int i, int t) {
          if (i == a.size()) {
               return 0;
          }
          if (dp[i][t] != -1) {
               return dp[i][t];
          }
          int ans = max(calc(a, i + 1, t), calc(a, i + 1, t + 1) + a[i] * t);
          return dp[i][t] = ans;
     }
     int maxSatisfaction(vector<int>& a) {
          sort(begin(a), end(a));
          memset(dp, -1, sizeof(dp));
          return calc(a, 0, 1);
     }
};