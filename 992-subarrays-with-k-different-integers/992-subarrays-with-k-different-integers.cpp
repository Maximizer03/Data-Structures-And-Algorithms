class Solution {
public:
     int calc(vector<int>&nums, int k) {
          if (k < 0) {
               return 0;
          }
          int n = nums.size(), i = 0;
          unordered_map<int, int>m;
          int ans = 0;
          for (int j = 0; j < n; j++) {
               if (m[nums[j]] == 0) {
                    k--;
               }
               m[nums[j]]++;
               while (k < 0) {
                    m[nums[i]]--;
                    if (m[nums[i]] == 0) {
                         k++;
                    }
                    i++;
               }
               ans += (j - i + 1);
          }
          return ans;
     }
     int subarraysWithKDistinct(vector<int>& nums, int k) {
          return calc(nums, k) - calc(nums, k - 1);
     }
};