class Solution {
public:
	string stoneGameIII(vector<int>& s) {
		int n = s.size();
		vector<int>dp(n + 1, INT_MIN);
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			int sum = 0;
			for (int j = i; j <= i + 2 && j<=n-1; j++) {
				sum += s[j];
				if (j < n) {
					dp[i] = max(sum - dp[j + 1], dp[i]);
				}
			}
		}
		return (dp[0] > 0 ? "Alice" : (dp[0] < 0 ? "Bob" : "Tie"));
	}
};