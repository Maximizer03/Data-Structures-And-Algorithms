class Solution {
public:
	int dp[10][2][2];
	int calc(int i, int n, vector<int>&d, int tight, int lead, string &num) {
		if (i == n) {
			return 1;
		}
		if (dp[i][tight][lead] != -1) {
			return dp[i][tight][lead];
		}
		int ans = 0;
		if (lead) {
			ans += calc(i + 1, n, d, 0, 1, num);
		}
		int ub = tight ? num[i] - '0' : 9;
		for (auto &x : d) {
			if (x <= ub) {
				int no = num[i] - '0';
				ans += calc(i + 1, n, d, tight & (x == no), 0, num);
			}
		}
		return dp[i][tight][lead] = ans;
	}
	int atMostNGivenDigitSet(vector<string>& digits, int R) {
		vector<int>d;
		for (auto &x : digits) {
			int num = x[0] - '0';
			d.push_back(num);
		}
		string num = to_string(R);
		memset(dp, -1, sizeof(dp));
		return calc(0, num.size(), d, 1, 1, num) - 1;
	}
};