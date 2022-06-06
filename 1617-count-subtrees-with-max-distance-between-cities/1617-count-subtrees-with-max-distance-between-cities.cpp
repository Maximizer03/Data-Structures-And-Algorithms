class Solution {
public:
    vector<int> get(int src, vector<vector<int>>&g, int n) {
        queue<int>q;
        vector<int>dist(n), vis(n);
        q.push(src);
        vis[src] = 1;
        int steps = 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int v = q.front();
                q.pop();
                dist[v] = steps;
                for (auto &u : g[v]) {
                    if (!vis[u]) {
                        q.push(u);
                        vis[u] = 1;
                    }
                }
            }
            steps++;
        }
        return dist;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& e) {
        vector<vector<int>>g(n);
        for (int i = 0; i < e.size(); i++) {
            g[e[i][0] - 1].push_back(e[i][1] - 1);
            g[e[i][1] - 1].push_back(e[i][0] - 1);
        }
        vector<vector<int>>dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = get(i, g, n);
        }
        vector<int>ans(n - 1);
        for (int m = 1; m < (1 << n); m++) {
            int tot = __builtin_popcount(m), cnt = 0;
            int mx = 0;
            for (int j = 0; j < n; j++) {
                if ((1 << j)&m) {
                    for (int k = 0; k < n && k != j; k++) {
                        if ((1 << k)&m) {
                            // direct edge
                            if (dp[j][k] == 1) {
                                cnt++;
                            }
                            mx = max(mx, dp[j][k]);
                        }
                    }
                }
            }
            if (cnt == tot - 1 && mx > 0) {
                ans[mx - 1]++;
            }
        }
        return ans;
    }
};