class Solution {
public:
	int dp[11][2][2][1024];
	int calc(int i, int n, int tight, int lead, int mask, string &num) {
		if (i == n) {
			return 1;
		}
		if (dp[i][tight][lead][mask] != -1) {
			return dp[i][tight][lead][mask];
		}
		int no = num[i] - '0';
		int ub = tight ? no : 9;
		int ans = 0;
		if (!lead) {
			int bit = mask & 1;
			if (bit == 0) {
				ans += calc(i + 1, n, (tight & (no == 0)), 0, (mask | 1), num);
			}
		}
		else {
			ans += calc(i + 1, n, 0, 1, mask, num);
		}
		for (int dig = 1; dig <= ub; dig++) {
			int bit = (1 << dig)&mask;
			if (bit == 0) {
				ans += calc(i + 1, n, ((tight) & (no == dig)), 0, (mask | (1 << dig)), num);
			}
		}
		return dp[i][tight][lead][mask] = ans;

	}
	int numDupDigitsAtMostN(int R) {
		string num = to_string(R);
		memset(dp, -1, sizeof(dp));
		return R - calc(0, num.size(), 1, 1, 0, num) + 1;
	}
};