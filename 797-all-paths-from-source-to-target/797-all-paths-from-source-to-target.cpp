class Solution {
public:
     void dfs(int v, vector<vector<int>>& g, vector<vector<int>>&paths, vector<int>&path ) {
          path.push_back(v);
          if (v == g.size() - 1) {
               paths.push_back(path);
          }
          else {
               for (auto u : g[v]) {
                    dfs(u, g, paths, path);
               }
          }
          path.pop_back();
     }
     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
          vector<vector<int>>paths;
          vector<int>path;
          int n = g.size();
          dfs(0, g, paths, path);
          return paths;
     }
};