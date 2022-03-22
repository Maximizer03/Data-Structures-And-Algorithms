class Solution {
public:
    int dp[105][105][2];
	int calc(int i, int m, vector<int>&a, int p) {
		int n = a.size();
		if (i == n) {
			return 0;
		}
        if(dp[i][m][p]!=-1){
            return dp[i][m][p];
        }
		int ans = 0;
		if (p == 1) {
			int sum = 0;
			for (int j = i; j <= min(n - 1, 2 * m + i - 1); j++) {
				sum += a[j];
				ans = max(ans, calc(j + 1, max(m, j - i + 1), a, 0) + sum);
			}
		}
		else {
            int t=1e9;
			for (int j = i; j <= min(n - 1, 2 * m + i - 1); j++) {
				t = min(t, calc(j + 1, max(m, j - i + 1), a, 1));
			}
            ans=t;
		}
		return dp[i][m][p]=ans;
	}
	int stoneGameII(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
		return calc(0, 1, a, 1);
	}
};