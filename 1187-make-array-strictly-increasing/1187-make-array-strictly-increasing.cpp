class Solution {
public:
    int dp[2005][2][2005];
    int calc(int i, int c, int p, vector<int>&arr1, vector<int>&arr2) {
        int n = arr1.size(), m = arr2.size();
        if (i == n) {
            return 0;
        }
        if (dp[i][c][p] != -1) {
            return dp[i][c][p];
        }
        int ans = 1e9;
        if (i == 0) {
            ans = calc(i + 1, 0, 0, arr1, arr2);
            ans = min(ans, 1 + calc(i + 1, 1, 0, arr1, arr2));
        }
        else {
            if (c == 1) {
                // not change current
                if (arr1[i] > arr2[p]) {
                    ans = min(ans, calc(i + 1, 0, 0, arr1, arr2));
                }
                // change currrent
                int j = upper_bound(begin(arr2), end(arr2), arr2[p]) - arr2.begin();
                if (j < m) {
                    ans = min(ans, calc(i + 1, 1, j, arr1, arr2) + 1);
                }
            }
            else {
                // not change current
                if (arr1[i] > arr1[i - 1]) {
                    ans = min(ans, calc(i + 1, 0, 0, arr1, arr2));
                }
                // change currrent
                int j = upper_bound(begin(arr2), end(arr2), arr1[i - 1]) - arr2.begin();
                if (j < m) {
                    ans = min(ans, calc(i + 1, 1, j, arr1, arr2) + 1);
                }
            }
        }
        return dp[i][c][p] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp, -1, sizeof(dp));
        sort(begin(arr2), end(arr2));
        int ans = calc(0, 0, 0, arr1, arr2);
        if (ans == 1e9) {
            return -1;
        }
        return ans;
    }
};