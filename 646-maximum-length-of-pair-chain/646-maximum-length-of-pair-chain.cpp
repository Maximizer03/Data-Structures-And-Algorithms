class Solution {
public:
	int dp[1005][2005];
	int calc(int i, int pi, vector<vector<int>>&pairs) {
		if (i == pairs.size()) {
			return 0;
		}
		if (dp[i][pi] != -1) {
			return dp[i][pi];
		}
		int ans = calc(i + 1, pi, pairs);
		int prev = pairs[pi][1];
		if (pairs[i][0] > prev) {
			ans = max(ans, calc(i + 1, i, pairs) + 1);
		}
		return dp[i][pi] = ans;
	}
	int findLongestChain(vector<vector<int>>& pairs) {
		pairs.push_back({ -2005, -2005});
		sort(begin(pairs), end(pairs));
		int n = pairs.size();
		memset(dp, -1, sizeof(dp));
		return calc(1, 0, pairs);
	}
};