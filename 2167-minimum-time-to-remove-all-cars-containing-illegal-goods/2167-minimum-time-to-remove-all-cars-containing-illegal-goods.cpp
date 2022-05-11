class Solution {
public:
	int minimumTime(string s) {
		int n = s.size();
		vector<int>suff(n, 0);
		suff[n - 1] = (s[n - 1] - '0');
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == '0') {
				suff[i] = suff[i + 1];
			}
			else {
				suff[i] = min(suff[i + 1] + 2, n - i);
			}
		}
		int ans = suff[0];
		for (int i = 0; i < n - 1; i++) {
			ans = min(ans, i + 1 + suff[i + 1]);
		}
		return ans;
	}
};