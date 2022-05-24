class Solution {
public:
	int req;
	int dp[(1 << 16)][16];
	int sub[(1 << 16)];
	int calc(int mask, int n, int k, vector<int>&a) {
		if (mask == (1 << n) - 1) {
			return (k == 0);
		}
		if (k <= 0) {
			return mask == (1 << n) - 1;
		}
		if (dp[mask][k] != -1) {
			return dp[mask][k];
		}
		bool ans = 0;
		for (int m2 = 0; m2 < (1 << n); m2++) {
			if ((m2 & mask) == 0) {
				if (sub[m2] == req) {
					int nm = (mask | m2);
					ans = (ans | (calc(nm, n, k - 1, a)));
				}
			}
		}
		return dp[mask][k] = ans;
	}
	bool canPartitionKSubsets(vector<int>& a, int k) {
		int sum = 0, n = a.size();
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		req = sum / k;
		if (sum % k != 0) {
			return false;
		}
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				int b = (1 << j)&i;
				if (b) {
					sub[i] += a[j];
				}
			}
		}
		memset(dp, -1, sizeof(dp));
		return calc(0, n, k, a);
	}
};