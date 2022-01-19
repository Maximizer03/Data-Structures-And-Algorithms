class NumArray {
private:
     int n;
     vector<int>dp;
public:
     NumArray(vector<int>& nums) {
          n = nums.size();
          dp = vector<int>(n + 1, 0);
          // dp[i+1]=> sum of array [0,i]
          for (int i = 1; i <= n; i++) {
               dp[i] = dp[i - 1] + nums[i - 1];
          }
     }

     int sumRange(int l, int r) {
          l++; r++;
          int ans = dp[r] - dp[l - 1];
          return ans;
     }
};