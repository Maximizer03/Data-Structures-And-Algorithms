class Solution {
public:
     int maxOperations(vector<int>& nums, int k) {
          int n = nums.size(), ans = 0;
          unordered_map<int, int>m;
          for (int i = 0; i < n; i++) {
               int x = nums[i];
               int y = k - x;
               if (m[y] > 0) {
                    ans++;
                    m[y]--;
               }
               else {
                    m[x]++;
               }
          }
          return ans;
     }
};