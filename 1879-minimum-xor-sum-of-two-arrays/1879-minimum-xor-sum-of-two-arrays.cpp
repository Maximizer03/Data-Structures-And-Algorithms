class Solution {
public:
	int calc(int mask) {
		int cnt = 0;
		while (mask) {
			cnt += (mask & 1);
			mask /= 2;
		}
		return cnt;
	}
	int minimumXORSum(vector<int>& a1, vector<int>& a2) {
		int n = a1.size();
		// dp[i][mask]=>  min xor sum considering the first i elements from a1 and subset mask from a2
		int N = (1 << n);
		vector<vector<int>>dp(n, vector<int>((1 << n), 1e9));
		for (int j = 0; j < n; j++) {
			dp[0][(1 << j)] = (a1[0] ^ a2[j]);
		}
		for (int i = 1; i < n; i++) {
			for (int mask = 0; mask < (1 << n); mask++) {
				if (calc(mask) == i) {
					for (int j = 0; j < n; j++) {
						int bit = (1 << j)&mask;
						if (bit == 0) {
							dp[i][(mask | (1 << j))] = min(dp[i][(mask | (1 << j))], dp[i - 1][mask] + (a1[i] ^ a2[j]));
						}
					}
				}
			}
		}
		return dp[n - 1][(1 << n) - 1];

	}
};