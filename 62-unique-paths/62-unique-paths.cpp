class Solution {
public:
     int uniquePaths(int n, int m) {
          long long ans = 1;
          for (int i = m + n - 2, j = 1; i >= max(n,m); i--, j++) {
               ans = (ans * i) / j;
          }
          return ans;
     }
};