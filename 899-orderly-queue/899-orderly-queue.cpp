class Solution {
public:
	string orderlyQueue(string s, int k) {
		int n = s.size();
		if (k > 1) {
			sort(begin(s), end(s));
			return s;
		}
		string sml = s;
		for (int i = -1; i < n - 1; i++) {
			string t = s.substr(i + 1, n - i - 1) + s.substr(0, i + 1);
			if (t < sml) {
				sml = t;
			}
		}
		return sml;
	}
};