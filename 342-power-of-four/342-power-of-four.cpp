class Solution {
public:
     bool isPowerOfFour(int n) {
          if (n <= 0) {
               return 0;
          }
          while (1) {
               if (n == 1) {
                    break;
               }
               if (n % 4 == 0) {
                    n = n / 4;
               }
               else {
                    return 0;
               }
          }
          return 1;
     }
};