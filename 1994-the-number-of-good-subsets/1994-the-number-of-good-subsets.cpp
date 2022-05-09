class Solution {
public:
	long long f[31], val[31], dp[32][1025], mod = 1e9 + 7;
	vector<int>pr;
	long long calc(int i, int mask, vector<int>&arr) {
		if (i == arr.size()) {
			return (mask > 0);
		}
		if (dp[i][mask] != -1) {
			return dp[i][mask] % mod;
		}
		long long op1 = calc(i + 1, mask, arr);
		long long sum = 0;
		int k = mask & val[arr[i]];
		if (k == 0) {
            
			sum = (f[arr[i]] % mod * calc(i + 1, (mask | val[arr[i]]), arr) % mod) % mod;
		}
		long long total = (sum + op1) % mod;
		return dp[i][mask] = (int)total;
	}
	bool chk(int n) {
		if (n == 1) {
			return 1;
		}
		for (int i = 0; i < pr.size(); i++) {
			int pro = pr[i] * pr[i];
			if (n % pro == 0) {
				return 0;
			}
		}
		return 1;
	}
	int numberOfGoodSubsets(vector<int>& A) {
		memset(f, 0, sizeof(f));
		memset(val, 0, sizeof(val));
		memset(dp, -1, sizeof(dp));
		for (int i : A) {
			f[i]++;
		}
		pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
		vector<int>arr;
		for (int i = 2; i <= 30; i++) {
			if (f[i] && chk(i)) {
				arr.push_back(i);
			}
		}
		for (int i = 0; i < (1 << 10); i++) {
			int p = 1;
			int m = 0;
			for (int j = 0; j < 10; j++) {
				int b = (1 << j)&i;
				if (b) {
					p *= pr[j];
					m = m | (1 << j);
					if (p > 30) {
						p /= pr[j];
						m = m ^ (1 << j);
					}
				}
			}
			val[p] = m;
		}
		int ans = calc(0, 0, arr);
        long long t= ans;
		for (int i = 0; i < f[1]; i++) {
            t= (t%mod * 2%mod)%mod;
		}
		return (int)(t);
	}
};