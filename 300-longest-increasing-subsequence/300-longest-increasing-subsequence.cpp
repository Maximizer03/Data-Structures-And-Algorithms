class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int l = lower_bound(begin(v), end(v), nums[i]) - v.begin();
			if (l == v.size()) {
				v.push_back(nums[i]);
			}
			else {
				v[l] = nums[i];
			}
		}
		return v.size();
	}
};