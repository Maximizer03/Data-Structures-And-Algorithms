class Solution {
public:
      int searchInsert(vector<int>& nums, int target) {
            int n = nums.size();
            int lo = 0, hi = n;
            while (lo < hi) {
                  int mid = lo + (hi - lo) / 2;
                  if (nums[mid] < target) {
                        lo = mid + 1;
                  }
                  else {
                        hi = mid;
                  }
            }
            return hi;
      }
};