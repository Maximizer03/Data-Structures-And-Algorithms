class Solution {
public:
	int dp[31][3100];
	bool calc(int i, int sum, vector<int>&s, vector<vector<int>>&dp) {
		if (sum < 0) {
			return 0;
		}
		int n = s.size();
		if (i == n) {
			return (sum == 0);
		}
		if (dp[i][sum] != -1) {
			return dp[i][sum];
		}
		int ans = calc(i + 1, sum, s, dp) | calc(i + 1, sum - s[i], s, dp);
		return dp[i][sum] = ans;
	}
	int lastStoneWeightII(vector<int>& s) {
		int n = s.size();
		sort(begin(s), end(s));
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += s[i];
		}
		vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
		int d = 1e9;
		for (int i = 1; i <= sum; i++) {
			if (calc(0, i, s, dp)) {
				int s1 = i, s2 = sum - i;
				d = min(d, abs(s1 - s2));
			}
		}
		return d;
	}
};