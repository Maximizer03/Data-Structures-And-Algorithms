class Solution {
public:
	int dp[12][(1 << 12)];
	int calc(int pi, int mask, int n, vector<int>&arr) {
		if (mask == (1 << n) - 1) {
			return 1;
		}
		if (dp[pi][mask] != -1) {
			return dp[pi][mask];
		}
		int ans = 0;
		set<int>s;
		for (int j = 0; j < n; j++) {
			int bit = (1 << j)&mask;
			if (bit == 0 && s.find(arr[j]) == s.end()) {
				int prev = arr[pi];
				int cur = arr[j];
				long long sum = prev + cur;
				long long sq = sqrt(sum);
				if (sq * sq == sum) {
					int new_mask = (mask | (1 << j));
					ans = ans +  calc(j, new_mask, n, arr);
				}
                s.insert(arr[j]);
			}
		}
		return dp[pi][mask] = ans;
	}
	int numSquarefulPerms(vector<int>& arr) {
		sort(begin(arr), end(arr));
		int n = arr.size();
		int ans = 0;
		set<int>s;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			if (s.find(arr[i]) == s.end()) {
				int mask = (1 << i);
				ans += calc(i, mask, n, arr);
				s.insert(arr[i]);
			}
		}
		return ans;
	}
};