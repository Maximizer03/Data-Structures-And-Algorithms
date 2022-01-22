class Solution {
public:
     vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
          using pivi = pair<int, vector<int>>;
          priority_queue<pivi, vector<pivi>, greater<pivi>>q;
          int n = v1.size(), m = v2.size();
          vector<int>num;
          int sum = v1[0] + v2[0];
         
          for (int i = 0; i < 2; i++) {
               num.push_back(0);
          }
         
          set<vector<int>>vis;
         
          vis.insert(num);
          q.push({sum, num});
         
         vector<vector<int>>ans;
         int cnt=0;
         
          while (cnt < k && !q.empty()) {
               vector<int>v = q.top().second;
               v[0] = v1[v[0]];
               v[1] = v2[v[1]];
               cnt++;
              cout<<v[0]<<" "<<v[1]<<endl;
               ans.push_back(v);
               vector<int>curr = q.top().second;
               q.pop();
               if (curr[0] + 1 < n) {
                    curr[0]++;
                    if (vis.find(curr) == vis.end()) {
                         int sum = v1[curr[0]] + v2[curr[1]];
                         q.push({sum, curr});
                         vis.insert(curr);
                    }
                    curr[0]--;
               }
               if (curr[1] + 1 < m) {
                    curr[1]++;
                    if (vis.find(curr) == vis.end()) {
                         int sum = v1[curr[0]] + v2[curr[1]];
                         q.push({sum, curr});
                         vis.insert(curr);
                    }
                    curr[1]--;
               }
          }
          return ans;
     }
};