class Solution {
public:
    int dp[100005][2];
    int calc(int i, int t, string &s, int n) {
        if (i == n) {
            return 0;
        }
        if (dp[i][t] != -1) {
            return dp[i][t];
        }
        int ans = 1e9;
        if (t == 0) {
            if (s[i] == '1') {
                ans = min(ans, calc(i + 1, 1, s, n));
                ans = min(ans, calc(i + 1, 0, s, n)+1);
            }
            else {
                ans = min(ans, calc(i + 1, 0, s, n));
            }
        }
        else {
            if (s[i] == '1') {
                ans = min(ans, calc(i + 1, 1, s, n));
            }
            else {
                ans = min(ans, calc(i + 1, 1, s, n) + 1);
            }
        }
        return dp[i][t] = ans;
    }
    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return calc(0, 0, s, n);
    }
};