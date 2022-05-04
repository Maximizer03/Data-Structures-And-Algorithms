class Solution {
public:
	int vis[11];
	int dp[11][2][2];
	int calc(int i, int n, int tight, int lead, string &num) {
		if (i == n) {
			return 1;
		}
		if (dp[i][tight][lead] != -1) {
			return dp[i][tight][lead];
		}
		int ub = tight ? num[i] - '0' : 9;
		int ans = 0;
		if (!lead) {
			if (!vis[0]) {
				vis[0] = 1;

				int no = num[i] - '0';
				int z = 0;
				ans += calc(i + 1, n, (tight & (no == z)), 0, num);

				vis[0] = 0;
			}
		}
		else {
			ans += calc(i + 1, n, 0, 1, num);
		}
		for (int dig = 1; dig <= ub; dig++) {
			if (vis[dig] == 0) {
				vis[dig] = 1;
				int no = num[i] - '0';
				ans += calc(i + 1, n, ((tight) & (no == dig)), 0, num);
				vis[dig] = 0;
			}
		}
		return ans;

	}
	int numDupDigitsAtMostN(int R) {
		string num = to_string(R);
		memset(vis, 0, sizeof(vis));
		memset(dp, -1, sizeof(dp));
		return R - calc(0, num.size(), 1, 1, num) + 1;
	}
};