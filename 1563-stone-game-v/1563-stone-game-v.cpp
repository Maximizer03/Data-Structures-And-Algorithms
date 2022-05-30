class Solution {
public:
	vector<int>p;
	int dp[505][505];
	int get(int l, int r) {
		int ans = p[r];
		if (l) {
			ans -= p[l - 1];
		}
		return ans;
	}
	int calc(int l, int r) {
		if (l >= r) {
			return 0;
		}
		if (dp[l][r] != -1) {
			return dp[l][r];
		}
		int ans = 0;
		for (int j = l; j <= r - 1; j++) {
			int left = get(l, j);
			int right = get(j + 1, r);
			if (left > right) {
				ans = max(ans,calc(j + 1, r) + right);
			}
			else if (left < right) {
				ans = max(ans,calc(l, j) + left);
			}
			else {
				ans = max(ans,left + max(calc(l, j), calc(j + 1, r)));
			}
		}
		return dp[l][r] = ans;
	}
	int stoneGameV(vector<int>& s) {
		int n = s.size();
		p.resize(n);
		p[0] = s[0];
		for (int i = 1; i < n; i++) {
			p[i] = p[i - 1] + s[i];
		}
		memset(dp, -1, sizeof(dp));
		return calc(0, n - 1);
	}
};