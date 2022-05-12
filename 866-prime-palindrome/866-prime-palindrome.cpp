class Solution {
public:
	bool isprime(int n) {
		if (n == 1) {
			return 0;
		}
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return 0;
			}
		}
		return 1;
	}
	int primePalindrome(int n) {
		vector<int>v;
		for (int i = 1; i <= 20000; i++) {
			string t = to_string(i);
			string k = t;
			reverse(begin(k), end(k));
			string l = t + k;
			t.pop_back();
			string r = t + k;
			if (l.size()) {
				v.push_back(stoi(l));
			}
			if (r.size()) {
				v.push_back(stoi(r));
			}
		}
		sort(begin(v), end(v));
		int l = lower_bound(begin(v), end(v), n) - v.begin();
		for (int i = l; i < v.size(); i++) {
			int num = v[i];
			if (isprime(num)) {
				return num;
			}
		}
		return -1;
	}
};