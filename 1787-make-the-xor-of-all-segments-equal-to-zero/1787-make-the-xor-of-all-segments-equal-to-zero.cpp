class Solution {
public:
    int minChanges(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>>f(k, vector<int>(1024));
        // for group  i,i+k,i+2k what is frequency of j
        vector<int>cnt(k);
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                cnt[i]++;
                f[i][arr[j]]++;
            }
        }
        vector<vector<int>>dp(k, vector<int>(1024, 1e9));
        int mn = 1e9;
        for (int j = 0; j < 1024; j++) {
            dp[0][j] = cnt[0] - f[0][j];
            mn = min(mn, dp[0][j]);
        }
        // dp[i][j]=> for subarray[0...i] min cost for xor to be j
        for (int i = 1; i < k; i++) {
            int mn2 = 1e9;
            for (int j = 0; j < 1024; j++) {
                dp[i][j] = min(dp[i][j], cnt[i] + mn);
                for (int r = i; r < n; r += k) {
                    int val = arr[r];
                    int req = j;
                    int new_val = val ^ req;
                    dp[i][j] = min(dp[i][j], dp[i - 1][new_val] + cnt[i] - f[i][val]);
                }
                mn2 = min(mn2, dp[i][j]);
            }
            mn = mn2;
        }
        return dp[k - 1][0];
    }
};