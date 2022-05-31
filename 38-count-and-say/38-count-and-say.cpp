class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 0; i < n - 1; i++) {
			string t = "";
			char cur = s[0], cnt = 1;
			for (int j = 1; j < s.size(); j++) {
				if (s[j] == s[j - 1]) {
					cnt++;
				}
				else {
					string c = to_string(cnt);
					t += c;
					t += cur;
					cur = s[j];
					cnt = 1;
				}
			}
			string c = to_string(cnt);
			t += c;
			t += cur;
			s = t;
		}
		return s;
	}
};