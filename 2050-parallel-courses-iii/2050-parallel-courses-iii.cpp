class Solution {
public:
     int minimumTime(int n, vector<vector<int>>& edges, vector<int>& a) {
          vector<int>g[n + 1], in(n + 1, 0);
          for (auto e : edges) {
               int u = e[0], v = e[1];
               g[u].push_back(v);
               in[v]++;
          }
          queue<int>q;
          vector<int>ord, dp(n + 1, 0);
          for (int i = 1; i <= n; i++) {
               if (in[i] == 0) {
                    q.push(i);
               }
          }
          while (!q.empty()) {
               int v = q.front();
               q.pop();
               ord.push_back(v);
               for (auto u : g[v]) {
                    in[u]--;
                    if (in[u] == 0) {
                         q.push(u);
                    }
               }
          }
          for (int i = 0; i < n; i++) {
               int v = ord[i];
               dp[v] += a[v - 1];
               for (auto u : g[v]) {
                    dp[u] = max(dp[u], dp[v]);
               }
          }
          return *max_element(begin(dp), end(dp));
     }
};