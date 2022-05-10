class Solution {
public:
	int dp[605][102][102];
	int N, M;
	// n 0's and m 1's
	// x 0's and y 1's
	int calc(int i, int x, int y, vector<vector<int>>&cnt) {
		if (i == cnt.size()) {
			return 1;
		}
        if(dp[i][x][y]!=-1){
            return dp[i][x][y];
        }
		int ans = calc(i + 1, x, y, cnt);
		if (cnt[i][0] + x <= N && cnt[i][1] + y <= M) {
			ans = max(ans, calc(i + 1, cnt[i][0] + x, cnt[i][1] + y, cnt) + 1);
		}
		return dp[i][x][y]=ans;
	}
	int findMaxForm(vector<string>& strs, int n, int m) {
		int s = strs.size();
		vector<vector<int>>cnt(s, vector<int>(2, 0));
		for (int i = 0; i < s; i++) {
			string t = strs[i];
			for (int j = 0; j < t.size(); j++) {
				cnt[i][(t[j] - '0')]++;
			}
		}
		N = n, M = m;
        memset(dp,-1,sizeof(dp));
		return calc(0, 0, 0, cnt)-1;
	}
};