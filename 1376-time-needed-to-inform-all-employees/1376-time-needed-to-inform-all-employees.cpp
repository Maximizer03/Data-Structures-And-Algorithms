class Solution {
private:
     vector<vector<int>>g;
     vector<int>tm;
public:
     int ans;
     void dfs(int v, int p,  int t) {
          ans = max(ans, t);
          for (auto u : g[v]) {
               if (u != p) {
                    dfs(u, v, t + tm[v]);
               }
          }
     }
     int numOfMinutes(int n, int root, vector<int>& m, vector<int>& informTime) {
          g = vector<vector<int>>(n);
          tm = informTime;
          for (int i = 0; i < n; i++) {
               if (m[i] != -1) {
                    g[m[i]].push_back(i);
                    g[i].push_back(m[i]);
               }
          }
          ans = 0;
          dfs(root, -1, 0);
          return ans;
     }
};