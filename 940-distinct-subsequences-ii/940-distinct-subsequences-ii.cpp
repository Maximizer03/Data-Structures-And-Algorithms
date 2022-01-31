class Solution {
public:
	int distinctSubseqII(string s) {
		int n = s.size();
		vector<int>dp(n + 1, 0);
		// dp[i]=> number of distinct subsequences when first i characters are taken
		// including the empty susbequences
		vector<long long>ind(26, -1);
		dp[0] = 1;
		const long long mod = 1e9 + 7;
		for (int i = 1; i <= n; i++) {
			int v = s[i - 1] - 'a';
			dp[i] = (dp[i - 1] % mod * 2 % mod) % mod;
			long long rep = 0;
			if (ind[v] != -1) {
				rep = dp[ind[v] - 1];
			}
			dp[i] = (dp[i] % mod - rep % mod + mod) % mod;
			ind[v] = i;
		}
		int ans = (dp[n] % mod - 1 % mod + mod) % mod;
		return ans;
	}
};