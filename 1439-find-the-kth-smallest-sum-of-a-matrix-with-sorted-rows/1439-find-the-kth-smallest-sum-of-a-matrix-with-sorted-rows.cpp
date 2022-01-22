class Solution {
public:
     int kthSmallest(vector<vector<int>>& a, int k) {
          using pivi = pair<int, vector<int>>;
          priority_queue<pivi, vector<pivi>, greater<pivi>>q;
          vector<int>vec, num;
          int n = a.size(), m = a[0].size(), sum = 0;
          for (int i = 0; i < n; i++) {
               sum += a[i][0];
               num.push_back(0);
          }
          set<vector<int>>vis;
          vis.insert(num);
          q.push({sum, num});
          while (vec.size() < k) {
               vec.push_back(q.top().first);
               vector<int>curr = q.top().second;
               q.pop();
               for (int i = 0; i < n; i++) {
                    if (curr[i] + 1 < m) {
                         curr[i]++;
                         if (vis.find(curr) == vis.end()) {
                              int sum = vec.back() + a[i][curr[i]] - a[i][curr[i] - 1];
                              q.push({sum, curr});
                              vis.insert(curr);
                         }
                         curr[i]--;
                    }
               }
          }
          return vec[k - 1];
     }
};