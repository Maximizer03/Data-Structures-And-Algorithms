class Solution {
public:
     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;
          vector<int>g[n], indegree(n, 0), order;
          for (auto x : prerequisites) {
               int a = x[0], b = x[1];
               g[b].push_back(a);
               indegree[a]++;
          }
          queue<int>q;
          for (int i = 0; i < n; i++) {
               if (indegree[i] == 0) {
                    q.push(i);
               }
          }
          while (!q.empty()) {
               int v = q.front();
               q.pop();
               order.push_back(v);
               for (auto u : g[v]) {
                    indegree[u]--;
                    if (indegree[u] == 0) {
                         q.push(u);
                    }
               }
          }
          if (order.size() == n) {
               return order;
          }
          else {
               return {};
          }
     }
};