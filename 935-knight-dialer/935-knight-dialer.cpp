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
        g = vector<vector<int>>(10);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x = i, y = j;
                for (int k = 0; k < 8; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) {
                        int u = x * 3 + y;
                        int v = xx * 3 + yy;
                        g[u].push_back(v);
                    }
                }
            }
        }
        int x = 3, y = 1;
        for (int k = 0; k < 8; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) {
                int u = 9;
                int v = xx * 3 + yy;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans % mod + calc(i, n) % mod) % mod;
        }
        return (int)(ans);
    }
};