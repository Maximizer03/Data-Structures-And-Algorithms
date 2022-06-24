class Solution {
public:
    long long mod;
    long long dp[10][5005];
    vector<vector<int>>g;
    long long calc(int v, int t) {
        if (t == 1) {
            return 1;
        }
        if (dp[v][t] != -1) {
            return dp[v][t];
        }
        long long ans = 0;
        for (auto &u : g[v]) {
            ans = (ans % mod + calc(u, t - 1) % mod) % mod;
        }
        return dp[v][t]=ans;
    }
    int knightDialer(int n) {
        mod = 1e9 + 7;
        vector<int>dx = { -1, -2, -2, -1, 1, 2, 2, 1};
        vector<int>dy = { -2, -1, 1, 2, -2, -1, 1, 2};
        g =  { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans % mod + calc(i, n) % mod) % mod;
        }
        return (int)(ans);
    }
};