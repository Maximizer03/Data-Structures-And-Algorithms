class Solution {
public:
	int longestPalindromeSubseq(string s) {
        if(s.size()==0){
            return 0;
        }
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
	int ans;
	void calc(int i, string s, int mask, int n) {
		if (i == n) {
			string s1 = "";
			string s2 = "";
			for (int j = 0; j < n; j++) {
				int bit = (1 << j)&mask;
				if (bit > 0) {
					s1 += s[j];
				}
				else {
					s2 += s[j];
				}
			}
			ans = max(ans, longestPalindromeSubseq(s1) * longestPalindromeSubseq(s2));
			return;
		}
		int newMask = (mask | (1 << i));
		calc(i + 1, s, newMask,n);
		calc(i + 1, s, mask,n);
	}
	int maxProduct(string s) {
		int mask = 0;
		ans = 0;
        int n=s.size();
		calc(0, s, mask,n);
		return ans;
	}
};