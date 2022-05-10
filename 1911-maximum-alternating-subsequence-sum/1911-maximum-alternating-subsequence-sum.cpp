class Solution {
public:
	long long maxAlternatingSum(vector<int>& nums) {
		int n = nums.size();
		vector<long long>prev(2), cur(2);
		prev[0] = prev[1] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int par = 0; par <= 1; par++) {
				long long ans = prev[par];
				long long x = nums[i];
				if (par % 2) {
					x *= -1;
				}
				ans = max(ans, prev[par ^ 1] + x);
				cur[par] = ans;
			}
			swap(prev, cur);
		}
		return prev[0];
	}
};