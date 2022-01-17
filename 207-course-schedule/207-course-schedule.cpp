class Solution {
public:
     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;
          vector<int>g[n];
          vector<int>indegree(n, 0);
          for (auto x : prerequisites) {
               int a = x[0];
               int b = x[1];
               g[b].push_back(a);
               indegree[a]++;
          }
          queue<int>q;
          for (int i = 0; i < n; i++) {
               if (indegree[i] == 0) {
                    q.push(i);
               }
          }
          int cnt = 0;
          while (!q.empty()) {
               int v = q.front();
               q.pop();
               cnt++;
               for (auto u : g[v]) {
                    indegree[u]--;
                    if (indegree[u] == 0) {
                         q.push(u);
                    }
               }
          }
          return cnt == n;
     }
};