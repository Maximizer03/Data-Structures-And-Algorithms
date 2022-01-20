class Solution {
public:
     void calc(int v, int tar, vector<vector<int>>& graph, vector<vector<int>>&ans, vector<int>path ) {
          if (v == tar) {
               path.push_back(tar);
               ans.push_back(path);
               return;
          }
          path.push_back(v);
          for (auto u : graph[v]) {
               vector<int>k = path;
               calc(u, tar, graph, ans, k);
          }
     }
     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
          vector<vector<int>>ans;
          vector<int>path;
          int n = graph.size();
          calc(0, n - 1, graph, ans, path);
          return ans;
     }
};