class Solution {
public:
	int compress(vector<char>& c) {
		int n = c.size();
		char cur = c[0];
		int cnt = 1, j = 0;
		for (int i = 1; i < n; i++) {
			if (c[i] == cur) {
				cnt++;
			}
			else {
				if (cnt == 1) {
					c[j] = cur; j++;
				}
				else if (cnt < 10) {
					c[j] = cur; j++;
					c[j] = cnt + '0'; j++;
				}
				else {
					c[j] = cur; j++;
					string s = to_string(cnt);
					reverse(begin(s), end(s));
					while (s.size()) {
						c[j] = s.back();
						s.pop_back(); j++;
					}
				}
				cnt = 1; cur = c[i];
			}
		}
		if (cnt == 1) {
			c[j] = cur; j++;
		}
		else if (cnt < 10) {
			c[j] = cur; j++;
			c[j] = cnt + '0'; j++;
		}
		else {
			string s = to_string(cnt);
			c[j] = cur; j++;
			reverse(begin(s), end(s));
			while (s.size()) {
				c[j] = s.back();
				s.pop_back(); j++;
			}
		}
		return j;
	}
};