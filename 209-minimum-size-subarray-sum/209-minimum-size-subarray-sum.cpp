class Solution {
public:
     int minSubArrayLen(int target, vector<int>& nums) {
          int n = nums.size();
          vector<long long>sums(n + 1, 0);
          for (int i = 1; i <= n; i++) {
               sums[i] = sums[i - 1] + nums[i - 1];
          }
          if (sums[n] < target) {
               return 0;
          }
          int mx = n;
          for (int i = 1; i <= n; i++) {
               int l = lower_bound(sums.begin(), sums.end(), target + sums[i - 1]) - sums.begin();
               if (l == n + 1) {
                    l--;
               }
               long long total = sums[l] - sums[i - 1];
               if (total >= target) {
                    mx = min(mx, l - i + 1);
               }
          }
          return mx;

     }
};