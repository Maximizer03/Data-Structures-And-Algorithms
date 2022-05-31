class Solution {
public:
	string convert(string s, int n) {
		vector<vector<char>>a(n);
        if(n==1){
            return s;
        }
		int st = 0;
		int l = 0, r = 1, d = 0;
		while (l < s.size()) {
			if (d == 0) {
				a[r - 1].push_back(s[l]);
				r++;
				if (r == n + 1) {
					r -= 2;
					d = 1;
				}
			}
			else {
				a[r - 1].push_back(s[l]);
				r--;
				if (r == 0) {
					r += 2;
					d = 0;
				}
			}
			l++;
		}
		string ans = "";
		for (int i = 0; i < n; i++) {
			for (auto &x : a[i]) {
				ans += x;
			}
		}
		return ans;
	}
};