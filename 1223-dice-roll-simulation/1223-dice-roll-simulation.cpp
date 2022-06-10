class Solution {
public:
    vector<int>v;
    long long dp[5005][7][16];
    long long mod;
    long long calc(int i, int p, int cnt, int n) {
        if (i == n) {
            return 1;
        }
        if (dp[i][p][cnt] != -1) {
            return dp[i][p][cnt];
        }
        long long ans = 0;
        for (int j = 0; j < 6; j++) {
            if (j == p) {
                if (cnt + 1 <= v[j]) {
                    ans = (ans % mod + calc(i + 1, j, cnt + 1, n) % mod) % mod;
                }
            }
            else {
                ans = (ans % mod + calc(i + 1, j, 1, n) % mod) % mod;
            }
        }
        return dp[i][p][cnt] = ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        v = rollMax;
        mod = 1e9 + 7;
        memset(dp, -1, sizeof(dp));
        long long ans = calc(0, 6, 0, n) % mod;
        return (int)ans;
    }
};