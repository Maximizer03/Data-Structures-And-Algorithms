class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int>cnt(32, 0);
		for (int x : nums) {
			x = abs(x);
			for (int j = 0; j < 32; j++) {
				int bit = (1LL << j)&x;
				if (bit) {
					cnt[j]++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			if (cnt[i] % 3 == 1) {
				ans = ans | (1 << i);
			}
		}
		int v = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == ans) {
				v++;
			}
		}
		if (v == 1) {
			return ans;
		}
		else {
			return -1 * ans;
		}
	}
};