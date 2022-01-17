class Solution {
public:
      int countPrimes(int n) {
            // Sieve of Eratosthenes
            // Time Complexity : O(nlog(log(n)))
            // Space Complexity: O(n)
            if (n == 0) {
                  return 0;
            }
            vector<bool>prime(n, true);
            prime[0] = prime[1] = false;
            int cnt = 0;
            for (long long i = 0; i < n; i++) {
                  if (prime[i]) {
                        cnt++;
                        for (long long j = i * i; j < n; j += i) {
                              prime[j] = false;
                        }
                  }
            }
            return cnt;
      }
};