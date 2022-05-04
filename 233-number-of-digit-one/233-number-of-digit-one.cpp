class Solution {
public:
	int dp[10][2][2][11];
	int calc(int i, int tight, int lead, string &num, int n, int cnt) {
		if (i == n) {
			return cnt;
		}
		if (dp[i][tight][lead][cnt] != -1) {
			return dp[i][tight][lead][cnt];
		}
		int ans = 0;
		int no = num[i] - '0';
		if (lead) {
			ans += calc(i + 1, 0, 1, num, n, cnt);
		}
		else {
			ans += calc(i + 1, (tight & (no == 0)), 0, num, n, cnt);
		}
		int ub = tight ? no : 9;
		for (int d = 1; d <= ub; d++) {
			if (d == 1) {
				ans += calc(i + 1, tight & (no == d), 0, num, n, cnt + 1) ;
			}
			else {
				ans += calc(i + 1, tight & (no == d), 0, num, n, cnt) ;
			}
		}
		return dp[i][tight][lead][cnt] = ans;
	}
	int countDigitOne(int R) {
		string num = to_string(R);
		memset(dp, -1, sizeof(dp));
		return calc(0, 1, 1, num, num.size(), 0);
	}
};