class Solution {
public:
    vector<vector<int>>g;
    long long dp[20005][6];
    long long mod;
    int calc(int i, int p, int n) {
        if (i == n) {
            return 1;
        }
        if (dp[i][p] != -1) {
            return dp[i][p];
        }
        long long ans = 0;
        for (int j = 0; j < g[p].size(); j++) {
            ans = (ans % mod + calc(i + 1, g[p][j], n) % mod) % mod;
        }
        return dp[i][p] = ans;
    }
    int countVowelPermutation(int n) {
        g = vector<vector<int>>(5);
        // a e i o u
        // 0 1 2 3 4
        g[0] = {1};
        g[1] = {0, 2};
        g[2] = {0, 1, 3, 4};
        g[3] = {2, 4};
        g[4] = {0};
        mod = 1e9 + 7;
        memset(dp,-1,sizeof(dp));
        long long ans = 0;
        for (int i = 0; i < 5; i++) {
            ans = (ans % mod + calc(1, i, n) % mod) % mod;
        }
        return (int)ans;
    }
};