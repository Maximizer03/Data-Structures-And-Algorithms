class Solution {
public:
	string subStrHash(string s, int P, int mod, int k, int h) {
		int n = s.size();
        long long MOD=mod;
        vector<long long>pows,hashs;
		pows.resize(n + 1, 0);
		hashs.resize(n + 1, 0);
		pows[0] = 1;
		for(int i = n - 1; i >= 0; i--) {
			hashs[i] = (1LL * hashs[i + 1] * P + s[i] - 'a' + 1) % MOD;
			pows[n - i] = (1LL * pows[n - i - 1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n - 1] * P) % MOD;
        
        function<int(int,int)> get_hash=[&](int l, int r) {
		    int ans = hashs[l] + MOD - (1LL * hashs[r + 1] * pows[r - l + 1]) % MOD;
		    ans %= MOD;
		    return ans;
	    };
		for (int st = 0; st <= n - k; st++) {
			int i = st, j = i + k - 1;
			if (get_hash(i, j) == h) {
				return s.substr(st, k);
			}
		}
		return "";
	}

};