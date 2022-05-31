class Solution {
public:
	bool hasAllCodes(string s, int k) {
		int n = s.size();
		set<int>st;
		for (int i = 0; i + k <= n; i++) {
			string t = s.substr(i, k);
			int p = 1, ans = 0;
			while (t.size() > 0) {
				int d = t.back() - '0';
				t.pop_back();
				ans += p * d;
				p *= 2;
			}
			st.insert(ans);
		}
		if (st.size() == (1 << k) && *st.rbegin() == (1 << k) - 1) {
			return true;
		}
		return false;
	}
};