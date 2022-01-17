class Solution {
public:
     int minPairSum(vector<int>& nums) {
          int n = nums.size();
          sort(begin(nums), end(nums));
          int l = 0, r = n - 1, mx = 0;
          while (l < r) {
               mx = max(mx, nums[l] + nums[r]);
               l++; r--;
          }
          return mx;
     }
};