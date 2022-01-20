class Solution {
public:
     int minNumberOperations(vector<int>& height) {
          // dp[i]=> min no of moves to build the blocks till i
          int n = height.size();
          int previous_state = height[0], current_state = height[0];
          for (int i = 1; i < n; i++) {
               if (height[i] <= height[i - 1]) {
                    current_state = previous_state;
               }
               else {
                    current_state = previous_state + (height[i] - height[i - 1]);
               }
               previous_state = current_state;
          }
          return current_state;
     }
};