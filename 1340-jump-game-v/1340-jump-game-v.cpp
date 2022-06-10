class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>>g(n);
        vector<int>in(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int j = i + 1;
            while (j < n && (j - i) <= d && arr[j] < arr[i]) {
                g[i].push_back(j);
                in[j]++;
                j++;
            }
        }
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && (i - j) <= d && arr[j] < arr[i]) {
                g[i].push_back(j);
                in[j]++;
                j--;
            }
        }
        queue<int>q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int>dp(n, 1);
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int v = q.front();
                q.pop();
                for (auto &u : g[v]) {
                    dp[u] = max(dp[u], dp[v] + 1);
                    in[u]--;
                    if (in[u] == 0) {
                        q.push(u);
                    }
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};