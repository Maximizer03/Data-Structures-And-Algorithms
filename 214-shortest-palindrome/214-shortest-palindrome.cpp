class Solution {
public:
	int N;
	const int mod = 1e9 + 7, mod2 = 1e9 + 9, base = 33;
	vector<int>pw, inv, hash;
	vector<int>pw2, inv2, hash2;
	int add(int a, int b, int m) {
		int res = (a + b) % m;
		if (res < 0) {
			res += m;
		}
		return res;
	}
	int mult(int a, int b, int m) {
		int res = (a * 1LL * b) % m;
		if (res < 0) {
			res += m;
		}
		return res;
	}
	int power(int a, int b, int m) {
		int res = 1;
		while (b) {
			if (b % 2 == 1) {
				b--;
				res = mult(res, a, m);
			}
			else {
				b = b / 2;
				a = mult(a, a, m);
			}
		}
		return res;
	}
	void precalc() {
		pw[0] = 1;
		for (int i = 1; i < N; i++) {
			pw[i] = mult(pw[i - 1], base, mod);
		}
		int pw_inv = power(base, mod - 2, mod);
		inv[0] = 1;
		for (int i = 1; i < N; i++) {
			inv[i] = mult(inv[i - 1], pw_inv, mod);
		}
	}
	void build(string s) {
		int n = s.size();
		hash[0] = mult(s[0] - 'a' + 1, pw[0], mod);
		for (int i = 1; i < n; i++) {
			hash[i] = add(hash[i - 1], mult(s[i] - 'a' + 1, pw[i], mod), mod);
		}
	}
	int gethash(int l, int r) {
		int t = hash[r];
		if (l > 0) {
			t = add(t, -hash[l - 1], mod);
		}
		t = mult(t, inv[l], mod);
		return t;
	}
	void precalc2() {
		pw2[0] = 1;
		for (int i = 1; i < N; i++) {
			pw2[i] = mult(pw2[i - 1], base, mod2);
		}
		int pw_inv = power(base, mod2 - 2, mod2);
		inv2[0] = 1;
		for (int i = 1; i < N; i++) {
			inv2[i] = mult(inv2[i - 1], pw_inv, mod2);
		}
	}
	void build2(string s) {
		int n = s.size();
		hash2[0] = mult(s[0] - 'a' + 1, pw2[0], mod2);
		for (int i = 1; i < n; i++) {
			hash2[i] = add(hash2[i - 1], mult(s[i] - 'a' + 1, pw2[i], mod2), mod2);
		}
	}
	int gethash2(int l, int r) {
		int t = hash2[r];
		if (l > 0) {
			t = add(t, -hash2[l - 1], mod2);
		}
		t = mult(t, inv2[l], mod2);
		return t;
	}
	vector<pair<int, int>> getPair(string &s, int rev) {
		int n = s.size();
		pw.resize(N, 0), hash.resize(N, 0), inv.resize(N, 0);
		pw2.resize(N, 0), hash2.resize(N, 0), inv2.resize(N, 0);
		precalc(); precalc2();
		build(s); build2(s);
		vector<pair<int, int>>res(n);
		if (!rev) {
			for (int i = 0; i < n; i++) {
				int l = 0, r = i;
				int h1 = gethash(l, r);
				int h2 = gethash2(l, r);
				res[i] = {h1, h2};
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				int r = n - 1, l = n - i - 1;
				int h1 = gethash(l, r);
				int h2 = gethash2(l, r);
				res[i] = {h1, h2};
			}
		}
		return res;
	}
	string shortestPalindrome(string s) {
		N = s.size();
		int n = s.size();
        if(n==0){
            return  "";
        }
		vector<pair<int, int>>v1 = getPair(s, 0);
		reverse(s.begin(), s.end());
		vector<pair<int, int>>v2 = getPair(s, 1);
		string ans = "";
		int len = 0;
		for (int i = 0; i < n; i++) {
			if (v1[i] == v2[i]) {
				len = max(len, i + 1);
			}
		}
		reverse(begin(s), end(s));
		string rem = s.substr(len, n - len + 1);
		reverse(begin(rem), end(rem));
		rem += s;
		return rem;
	}
};