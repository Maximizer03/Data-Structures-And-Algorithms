class Solution {
public:
	vector<vector<int>>g;
	long long dp[41][1025], mod = 1e9 + 7;
	int cnt[41];
	long long calc(int i, int mask, int n, int m) {
		if (i == 41) {
			int req = (1 << n) - 1;
			return (req == mask);
		}
		if (dp[i][mask] != -1) {
			return dp[i][mask];
		}
		long long ans = calc(i + 1, mask, n, m) % mod;
		for (int x : g[i]) {
			long long bit = (1 << x)&mask;
			if (bit == 0) {
				ans = (ans % mod + calc(i + 1, (mask | (1 << x)) , n, m) % mod ) % mod;
			}
		}
		return dp[i][mask] = ans;
	}
	int numberWays(vector<vector<int>>& hats) {
		int n = hats.size();
		memset(cnt, 0, sizeof(cnt));
		g = vector<vector<int>>(41);
		for (int i = 0; i < n; i++) {
			for (auto x : hats[i]) {
				g[x].push_back(i);
				cnt[x]++;
			}
		}
		memset(dp, -1, sizeof(dp));
		int m = 41;
		return (int)calc(0, 0, n, m);
	}
};