class Solution {
public:
     bool canJump(vector<int>& nums) {
          // greedy solution
          // Time Complexity : O(n)
          // Space Complexity : O(1)
          int n = nums.size(), goal = n - 1;
          for (int i = n - 2; i >= 0; i--) {
               if (i + nums[i] >= goal) {
                    goal = i;
               }
          }
          return goal == 0;
     }
};