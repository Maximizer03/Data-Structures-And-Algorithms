class Solution {
public:
	int dp[5005][2][2];
	int calc(int i, int own, int cool, vector<int>&prices) {
		if (i == prices.size()) {
			return 0;
		}
		if (dp[i][own][cool] != -1) {
			return dp[i][own][cool];
		}
		if (own) {
			int op1 = calc(i + 1, 0, 1, prices) + prices[i];
			int op2 = calc(i + 1, 1, 0, prices);
			return dp[i][own][cool] = max(op1, op2);
		}
		else {
			int op1 = 0;
			if (!cool) {
				op1 = -prices[i] + calc(i + 1, 1, 0, prices);
			}
			int op2 = calc(i + 1, 0, 0, prices);
			return dp[i][own][cool] = max(op1, op2);
		}
	}
	int maxProfit(vector<int>& prices) {
		memset(dp, -1, sizeof(dp));
		return calc(0, 0, 0, prices);
	}
};