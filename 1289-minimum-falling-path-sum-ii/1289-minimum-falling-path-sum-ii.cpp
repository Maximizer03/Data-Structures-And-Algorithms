class Solution {
public:
     struct cmp {
          bool operator()(const pair<int, int>&a, const pair<int, int>&b) {
               return a.first < b.first;
          }
     };
     int minFallingPathSum(vector<vector<int>>& matrix) {
          int n = matrix.size();
          if (n == 1) {
               return matrix[0][0];
          }
          priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>q;
          for (int i = 0; i < n; i++) {
               q.push({matrix[0][i], i});
               if (q.size() > 2) {
                    q.pop();
               }
          }
          for (int i = 1; i < n; i++) {
               priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>k, r = q;
               int mn1 = r.top().first, idx1 = r.top().second;
               r.pop();
               int mn2 = r.top().first, idx2 = r.top().second;
               for (int j = 0; j < n; j++) {
                    if (j == idx2) {
                         k.push({mn1 + matrix[i][j], j});

                    }
                    else {
                         k.push({mn2 + matrix[i][j], j});
                    }
                    if (k.size() > 2) {
                         k.pop();
                    }
               }
               q = k;
          }
          q.pop();
          return q.top().first;
     }
};