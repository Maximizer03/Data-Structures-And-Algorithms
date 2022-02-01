class Solution {
private:
    vector<vector<int>>dp;
    string s;
public:
    int calc (int i, int j) {
			if (i == j) {
				return 1;
			}
			if (i + 1 == j) {
				return int(s[i] == s[j]);
			}
			if (dp[i][j] != -1) {
				return dp[i][j];
			}
			int ans = ((s[i] == s[j]) && calc(i + 1, j - 1));
			return dp[i][j] = ans;
		}
	string longestPalindrome(string k) {
        s=k;
        int n = s.size();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
		// dp[i][j]=> if the substring s[i,j] is a palindrome
		int mx = 1, st = 0, en = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (calc(i, j)) {
					int len = j - i + 1;
					if (len > mx) {
						mx = len;
						st = i;
						en = j;
					}
				}
			}
		}
		return s.substr(st,en-st+1);
	}
};