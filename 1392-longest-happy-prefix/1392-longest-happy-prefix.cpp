class Solution {
public:
	int N ;
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
	bool calc(int mid, string &s) {
		set<pair<int, int>>st;
		int n = s.size();
		int h1 = gethash(0, mid - 1);
		int h2 = gethash2(0, mid - 1);
		st.insert({h1, h2});
		h1 = gethash(n - mid, n - 1);
		h2 = gethash(n - mid, n - 1);
		st.insert({h1, h2});
		return st.size() == 1;
	}
	string longestPrefix(string s) {
		N = s.size();
		pw.resize(N), hash.resize(N), inv.resize(N);
		pw2.resize(N), hash2.resize(N), inv2.resize(N);
		precalc();
		build(s);
		precalc2();
		build2(s);
		int len = 0;
		int n = s.size();
		for (int i = 0; i < n - 1; i++) {
			int h1 = gethash(0, i);
			int h2 = gethash2(0, i);
			int h3 = gethash(n - i - 1, n - 1);
			int h4 = gethash2(n - i - 1, n - 1);
			if (h1 == h3 && h2 == h4) {
				if (i + 1 > len) {
					len = i + 1;
				}
			}
		}
		return s.substr(0, len);
	}
};