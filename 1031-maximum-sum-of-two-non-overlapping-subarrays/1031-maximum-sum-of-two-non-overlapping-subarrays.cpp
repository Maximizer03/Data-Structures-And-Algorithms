class Solution {
public:
    int dp[1005][2][2];
	int calc(int i, int n, int p1, int p2, int l1, int l2, vector<int>&arr) {
		if (i == n) {
			if (p1 == 1 && p2 == 1) {
				return 0;
			}
			else {
				return -1e9;
			}
		}
        if(dp[i][p1][p2]!=-1){
            return dp[i][p1][p2];
        }
		int ans = calc(i + 1, n, p1, p2, l1, l2, arr);
		if (p1 == 0) {
			if (i + l1 - 1 < n) {
				int sum = 0;
				for (int j = i; j < i + l1; j++) {
					sum += arr[j];
				}
				ans = max(ans, calc(i + l1, n, 1, p2, l1, l2, arr) + sum);
			}
		}
		if (p2 == 0) {
			if (i + l2 - 1 < n) {
				int sum = 0;
				for (int j = i; j < i + l2; j++) {
					sum += arr[j];
				}
				ans = max(ans, calc(i + l2, n, p1, 1, l1, l2, arr) + sum);
			}
		}
		return dp[i][p1][p2]=ans;
	}
	int maxSumTwoNoOverlap(vector<int>& arr, int l1, int l2) {
		int n = arr.size();
        memset(dp,-1,sizeof(dp));
		return calc(0, n, 0, 0, l1, l2, arr);
	}
};