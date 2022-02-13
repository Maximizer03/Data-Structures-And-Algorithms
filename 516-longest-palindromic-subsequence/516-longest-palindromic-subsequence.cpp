class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		vector<int>cur(n, 0), prev(n, 0);
		prev[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (i == j) {
					cur[j] = 1;
					continue;
				}
				if (s[i] == s[j]) {
					cur[j] = prev[j - 1] + 2;
				}
				else {
					cur[j] = max(cur[j - 1], prev[j]);
				}
			}
			swap(cur, prev);
		}
		return prev[n - 1];
	}
};