class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>>g[n + 1];
        int m = flights.size();
        for (int i = 0; i < m; i++) {
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            g[u].push_back({v, w});
        }
        // (dist,node,k)
        priority_queue< array<int, 3> , vector<array<int, 3>>, greater<array<int, 3>> >q;
        K++;
        vector<vector<int>>dp(n, vector<int>(K + 1, 1e9));
        // dp[i][K]=> cheapest flight price from source to node i with at most K stops
        q.push({0, src, K});
        for (int i = 0; i <= K; i++) {
            dp[src][i] = 0;
        }
        while (!q.empty()) {
            int d = q.top()[0], v = q.top()[1], k = q.top()[2];
            q.pop();
            if (d > dp[v][K]) {
                continue;
            }
            if (v == dst) {
                return d;
            }
            for (auto &[u, w] : g[v]) {
                if (k > 0) {
                    if (dp[u][k - 1] > dp[v][k] + w) {
                        dp[u][k - 1] = dp[v][k] + w;
                        q.push({dp[u][k - 1], u, k - 1});
                    }
                }
            }
        }
        return -1;
    }
};