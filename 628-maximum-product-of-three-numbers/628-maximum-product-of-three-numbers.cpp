class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(begin(nums), end(nums));
		int ans = -1e9;
		int n = nums.size();
		for (int i = n - 3; i < n; i++) {
			int p = 1;
			for (int j = i; j <= i + 2; j++) {
				p = p * nums[j % n];
			}
			ans = max(ans, p);
		}
		return ans;

	}
};