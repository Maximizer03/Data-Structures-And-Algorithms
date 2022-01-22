class Solution {
public:
     vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
          vector<int>d(n + 1, 0);
          int INF = 1e5;
          vector<vector<int>>dp(n + 1, vector<int>(n + 1, INF));
          for (int v = 0; v < n; v++) {
               dp[v][v] = 0;
          }
          for (auto e : edges) {
               dp[e[0] - 1][e[1] - 1] = 1;
               dp[e[1] - 1][e[0] - 1] = 1;
          }
          for (int k = 0; k < n; ++k) {
               for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                         if (dp[i][k] < INF && dp[k][j] < INF) {
                              dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                         }
                    }
               }
          }
          for (int mask = 1; mask < (1 << n); mask++) {
               vector<int>node;
               for (int v = 0; v < n; v++) {
                    int bit = (1 << v)&mask;
                    if (bit > 0) {
                         node.push_back(v);
                    }
               }
               int cnt = 0;
               for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                         int b1 = (1 << i)&mask;
                         int b2 = (1 << j)&mask;
                         if (b1 > 0 && b2 > 0) {
                              if (dp[i][j] == 1) {
                                   cnt++;
                              }
                         }
                    }
               }
               if (cnt == node.size() - 1) {
                    int mx = 0;
                    for (auto x : node) {
                         for (auto y : node) {
                              mx = max(mx, dp[x][y]);
                         }
                    }
                    d[mx]++;
               }
          }
          vector<int>ans;
          for (int i = 1; i <= n - 1; i++) {
               ans.push_back(d[i]);
          }
          return ans;
     }
};