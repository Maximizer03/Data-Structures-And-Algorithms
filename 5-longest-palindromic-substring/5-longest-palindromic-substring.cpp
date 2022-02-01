class Solution {
public:
    int dp[1005][1005];
    int calc (int i, int j,string &s) {
			if (i == j) {
				return 1;
			}
			if (i + 1 == j) {
				return int(s[i] == s[j]);
			}
			if (dp[i][j] != -1) {
				return dp[i][j];
			}
			int ans = ((s[i] == s[j]) && calc(i + 1, j - 1, s));
			return dp[i][j] = ans;
		}
	string longestPalindrome(string s) {
		int n = s.size();
        memset(dp,-1,sizeof(dp));
		vector<vector<int>>dp(n, vector<int>(n, -1));
		// dp[i][j]=> if the substring s[i,j] is a palindrome
		int mx = 1, st = 0, en = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (calc(i, j, s)) {
					int len = j - i + 1;
					if (len > mx) {
						mx = len;
						st = i;
						en = j;
					}
				}
			}
		}
		string ans = "";
		for (int i = st; i <= en; i++) {
			ans += s[i];
		}
		return ans;
	}
};