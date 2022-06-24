class Solution {
public:
    int dp[400];
    vector<int>p;
    int calc(int i, int n, vector<int>&d, vector<int>&c) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 1e9;
        for (int k = 0; k < 3; k++) {
            int j = lower_bound(d.begin(), d.end(), d[i] + p[k]) - d.begin();
            ans = min(ans, calc(j, n, d, c) + c[k]);
        }
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& d, vector<int>& c) {
        memset(dp, -1, sizeof(dp));
        int n = d.size();
        p = {1, 7, 30};
        return calc(0, n, d, c);
    }
};