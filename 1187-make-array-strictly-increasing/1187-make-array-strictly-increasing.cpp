class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        sort(begin(arr2), end(arr2));
        int dp[n + 1][2][m];
        memset(dp, 1e9, sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 2; j++) {
                dp[n][j][i] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 2; c++) {
                for (int p = 0; p < m; p++) {
                    int ans = 1e9;
                    if (i == 0) {
                        ans = dp[i + 1][0][0];
                        ans = min(ans, 1 + dp[i + 1][1][0]);
                    }
                    else {
                        if (c == 1) {
                            // not change current
                            if (arr1[i] > arr2[p]) {
                                ans = min(ans, dp[i + 1][0][0]);
                            }
                            // change currrent
                            int j = upper_bound(begin(arr2), end(arr2), arr2[p]) - arr2.begin();
                            if (j < m) {
                                ans = min(ans, dp[i + 1][1][j] + 1);
                            }
                        }
                        else {
                            // not change current
                            if (arr1[i] > arr1[i - 1]) {
                                ans = min(ans, dp[i + 1][0][0]);
                            }
                            // change currrent
                            int j = upper_bound(begin(arr2), end(arr2), arr1[i - 1]) - arr2.begin();
                            if (j < m) {
                                ans = min(ans, dp[i + 1][1][j] + 1);
                            }
                        }
                    }
                    dp[i][c][p] = ans;
                }
            }
        }
        int ans = dp[0][0][0];
        if (ans == 1e9) {
            return -1;
        }
        return ans;
    }
};