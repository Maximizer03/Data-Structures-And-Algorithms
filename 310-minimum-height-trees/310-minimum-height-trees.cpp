class Solution {
public:
     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
          if (n == 1) {
               return {0};
          }
          vector<int>g[n];
          vector<int>indegree(n, 0);
          for (auto x : edges) {
               int u = x[0], v = x[1];
               g[u].push_back(v);
               g[v].push_back(u);
               indegree[u]++;
               indegree[v]++;
          }
          vector<int>leaves;
          for (int i = 0; i < n; i++) {
               if (indegree[i] == 1) {
                    leaves.push_back(i);
               }
          }
          while (n > 2) {
               vector<int>new_leaves;
               for (auto v : leaves) {
                    for (auto u : g[v]) {
                         indegree[u]--;
                         if (indegree[u] == 1) {
                              new_leaves.push_back(u);
                         }
                    }
               }
               n-=leaves.size();
               leaves = new_leaves;
          }
          return leaves;
     }
};