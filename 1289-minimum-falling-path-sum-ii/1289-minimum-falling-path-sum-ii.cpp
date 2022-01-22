class Solution {
public:
     vector<int> getSmallestTwo(vector<int>&v) {
          int n = v.size();
          vector<int>a(2, -1);
          for (int i = 0; i < n; i++) {
               if (a[0] == -1 || v[i] < v[a[0]]) {
                    a[1] = a[0];
                    a[0] = i;
               }
               else if (a[1] == -1 || v[i] < v[a[1]]) {
                    a[1] = i;
               }
          }
          return a;
     }
     int minFallingPathSum(vector<vector<int>>& A) {
          int n = A.size();
          if (n == 1) {
               return A[0][0];
          }
          for (int i = 1; i < n; i++) {
               auto a = getSmallestTwo(A[i - 1]);
               for (int j = 0; j < n; j++) {
                    if (a[0] == j) {
                         A[i][j] += A[i - 1][a[1]];
                    }
                    else {
                         A[i][j] += A[i - 1][a[0]];
                    }
               }
          }
          return *min_element(A[n - 1].begin(), A[n - 1].end());
     }
};