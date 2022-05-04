class Solution {
public:
	int dp[9][2][2][1020];
	int calc(int i, int tight, int lead, int n, string &num, int mask) {
		if (i == n) {
			return 1;
		}
		if (dp[i][tight][lead][mask] != -1) {
			return dp[i][tight][lead][mask];
		}
		int ans = 0;
		int no = num[i] - '0';
		if (lead) {
			ans += calc(i + 1, 0, 1, n, num, mask);
		}
		else {
			int bit = 1 & mask;
			if (bit == 0) {
				ans += calc(i + 1, tight & (no == 0), 0, n, num, mask | 1);
			}
		}
		int ub = tight ? no : 9;
		for (int d = 1; d <= ub; d++) {
			int bit = (1 << d)&mask;
			if (bit == 0) {
				ans += calc(i + 1, tight & (no == d), 0, n, num, mask | (1 << d));
			}
		}
		return dp[i][tight][lead][mask] = ans;
	}
	int countNumbersWithUniqueDigits(int n) {
		int R = pow(10, n) - 1;
		string num = to_string(R);
		memset(dp, -1, sizeof(dp));
		return calc(0, 1, 1, n, num, 0);
	}
};