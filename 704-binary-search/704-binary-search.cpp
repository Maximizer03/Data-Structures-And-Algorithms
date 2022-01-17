class Solution {
public:
      int search(vector<int>& nums, int target) {
            int n = nums.size();
            int lo = 0, hi = n - 1;
            while (lo < hi) {
                  // choose mid wisely thinking of only 2 elements left
                  int mid = lo + (hi - lo + 1) / 2;
                  // exclude mid always
                  if (nums[mid] > target) {
                        hi = mid - 1;
                  }
                  else {
                        lo = mid;
                  }
            }
            return nums[lo] == target ? lo : -1;
      }
};