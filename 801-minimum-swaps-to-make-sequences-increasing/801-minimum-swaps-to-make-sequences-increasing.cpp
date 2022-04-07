class Solution {
public:
	int calc(int i, int s, vector<int>&v1, vector<int>&v2, vector<vector<int>>&dp) {
		int n = v1.size();
		if (i == n) {
			return 0;
		}
		if (dp[i][s] != -1) {
			return dp[i][s];
		}
		int ans = 1e9;
		if (s == 1) {
			if (v1[i] > v2[i - 1] && v2[i] > v1[i - 1]) {
				ans = min(ans, calc(i + 1, 0, v1, v2, dp));
			}
			if (v2[i] > v2[i - 1] && v1[i] > v1[i - 1]) {
				ans = min(ans, calc(i + 1, 1, v1, v2, dp) + 1);
			}
		}
		else {
			if (v1[i] > v1[i - 1] && v2[i] > v2[i - 1]) {
				ans = min(ans, calc(i + 1, 0, v1, v2, dp));
			}
			if (v2[i] > v1[i - 1] && v1[i] > v2[i - 1]) {
				ans = min(ans, calc(i + 1, 1, v1, v2, dp) + 1);
			}
		}
		return dp[i][s] = ans;
	}
	int minSwap(vector<int>& nums1, vector<int>& nums2) {
		vector<int>v1 = { -1};
		vector<int>v2 = { -1};
		int n = nums1.size();
		for (int i = 0; i < n; i++) {
			v1.push_back(nums1[i]);
			v2.push_back(nums2[i]);
		}
		vector<vector<int>>dp(n + 1, vector<int>(2, -1));
		return calc(1, 0, v1, v2, dp);
	}
};