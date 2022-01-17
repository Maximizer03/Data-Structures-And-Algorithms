class Solution {
public:
     int firstMissingPositive(vector<int>& nums) {
          // try to put the number i at index i-1 leaving -ve and nos >n
         // dry run for [3,4,7,1]
          int n = nums.size();
          for (int i = 0; i < n; i++) {
               while (1) {
                    if (nums[i] <= 0 || nums[i] > n) {
                         break;
                    }
                    int cur = nums[i];
                    int pos = cur - 1;
                    if (nums[pos] != cur) {
                         swap(nums[pos], nums[i]);
                    }
                    else {
                         break;
                    }
               }
          }
          for (int i = 0; i < n; i++) {
               if (nums[i] != i + 1) {
                    return i + 1;
               }
          }
          return n + 1;
     }
};