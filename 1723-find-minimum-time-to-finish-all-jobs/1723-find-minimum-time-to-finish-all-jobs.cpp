class Solution {
public:
    int sub[(1 << 12)];
    int dp[12][(1 << 12)];
    int calc(int i, int mask, int n, int k) {
        if (i == k) {
            if (mask == 0) {
                return 0;
            }
            else {
                return 1e9;
            }
        }
        if (dp[i][mask] != -1) {
            return dp[i][mask];
        }
        int ans = 1e9;
        for (int m2 = mask ; m2 ; m2 = (m2 - 1)&mask ) {
            int sum = sub[m2];
            int new_mask = mask ^ m2;
            ans = min(ans, max(calc(i + 1, new_mask, n, k), sum));
        }
        return dp[i][mask] = ans;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                int b = (1 << j)&i;
                if (b) {
                    sub[i] += jobs[j];
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        return calc(0, (1 << n) - 1 , n, k);
    }
};