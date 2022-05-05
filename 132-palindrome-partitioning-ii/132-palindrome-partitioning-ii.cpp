class Solution {
public:
	bool isPalindrome(string &s) {
		int l = 0, r = s.size() - 1;
		while (l <= r) {
			if (s[l] == s[r]) {
				l++; r--;
			}
			else {
				return 0;
			}
		}
		return 1;
	}
	int calc(int i, string &s, int n, vector<int>&dp) {
		if (i == n) {
			return 0;
		}
		if (dp[i] != -1) {
			return dp[i];
		}
		int ans = INT_MAX;
		string temp = "";
		for (int j = i; j < n; j++) {
			temp += s[j];
			if (isPalindrome(temp)) {
				ans = min(ans, 1 + calc(j + 1, s, n, dp));
			}
		}
		return dp[i] = ans;
	}
	int minCut(string s) {
		int n = s.size();
		vector<int>dp(n, -1);
		return calc(0, s, n, dp) - 1;
	}
};