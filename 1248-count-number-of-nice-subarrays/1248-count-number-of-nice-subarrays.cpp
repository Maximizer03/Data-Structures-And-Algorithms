class Solution {
public:
     int numberOfSubarrays(vector<int>& nums, int k) {
          int n = nums.size();
          vector<int>sums(n + 1, 0);
          for (int i = 0; i < n; i++) {
               nums[i] = nums[i] % 2;
               sums[i + 1] = sums[i] + nums[i];
          }
          int ans = 0;
          for (int i = 1; i <= n; i++) {
               int x = sums[i - 1] + k;
               int cnt = upper_bound(sums.begin(), sums.end(), x) - lower_bound(sums.begin(), sums.end(), x);
               ans += cnt;
          }
          return ans;
     }
};