class Solution {
public:
     int minSubArrayLen(int s, vector<int>& nums) {
          int n = nums.size();
          int mx = n + 1,i = 0;
          for (int j = 0; j < n; j++) {
               s -= nums[j];
               while (s <= 0) {
                    int len = (j - i + 1);
                    mx = min(mx, len);
                    s += nums[i];
                    i++;
               }
          }
          return mx % (n + 1);
     }
};