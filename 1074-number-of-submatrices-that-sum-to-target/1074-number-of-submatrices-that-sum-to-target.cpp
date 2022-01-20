class Solution {
private:
     vector<vector<int>>dp;
public:
     int query(int r1, int c1, int r2, int c2) {
          r1++; c1++; r2++; c2++;
          int ans = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
          return ans;
     }
     int subarraySum(vector<int>& nums, int k) {
          unordered_map<int, int>m;
          int n = nums.size();
          m[0]++;
          int sum = 0, ans = 0;
          for (int i = 0; i < n; i++) {
               sum += nums[i];
               if (m.find(sum - k) != m.end()) {
                    ans += m[sum - k];
               }
               m[sum]++;
          }
          return ans;
     }
     int numSubmatrixSumTarget(vector<vector<int>>& a, int k) {
          int n = a.size(), m = a[0].size();
          dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
          for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= m; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i - 1][j - 1];
               }
          }
          int ans = 0;
          for (int r1 = 0; r1 < n; r1++) {
               for (int r2 = r1; r2 < n; r2++) {
                    vector<int>v;
                    for (int j = 0; j < m; j++) {
                         int sum = query(r1, j, r2, j);
                         v.push_back(sum);
                    }
                    ans += subarraySum(v, k);
               }
          }
          return ans;
     }
};