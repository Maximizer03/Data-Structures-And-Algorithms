class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(begin(pairs), end(pairs));
		int n = pairs.size();
		vector<int>dp(n, 1);
		int mx = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (pairs[i][0] > pairs[j][1]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			mx = max(mx, dp[i]);
		}
		return mx;
	}
};