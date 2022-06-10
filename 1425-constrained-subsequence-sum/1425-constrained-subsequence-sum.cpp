class Solution {
public:
    int constrainedSubsetSum(vector<int>& arr, int k) {
        deque<pair<int, int>>d;
        int n = arr.size();
        vector<int>dp(n);
        for (int i = 0; i < n; i++) {
            int mx = -1e9;
            while (d.size() > 0 && i - d.front().second > k) {
                d.pop_front();
            }
            if (d.size()) {
                mx = max(mx, d.front().first);
            }
            dp[i] = max(mx + arr[i], arr[i]);
            while (d.size() > 0 && d.back().first < dp[i]) {
                d.pop_back();
            }
            d.push_back({dp[i], i});
        }
        int ans = -1e9;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};