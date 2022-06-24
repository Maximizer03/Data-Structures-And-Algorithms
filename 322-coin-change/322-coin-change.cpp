class Solution {
public:
    long long dp[13][10005];
    long long calc(int i, int w, vector<int>&c, int n, int W) {
        if (i == n) {
            if (w == W) {
                return 0;
            }
            else {
                return 1e9;
            }
        }
        if (dp[i][w] != -1) {
            return dp[i][w];
        }
        long long ans = calc(i + 1, w, c, n, W);
        long long sum = (long long)c[i] + (long long)w;
        if (sum <= W) {
            ans = min(ans, 1 + calc(i, c[i] + w, c, n, W));
        }
        return dp[i][w] = ans;
    }
    int coinChange(vector<int>& c, int t) {
        memset(dp, -1, sizeof(dp));
        int n = c.size();
        long long W = t;
        int x = calc(0LL, 0LL, c, n, W);
        if (x == 1e9) {
            return -1;
        }
        return x;
    }
};