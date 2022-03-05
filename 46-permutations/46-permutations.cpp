class Solution {
public:
	void nextPermutation(vector<int>& nums, int &flg) {
		int n = nums.size(), k, l;
		for (k = n - 2; k >= 0; k--) {
			if (nums[k] < nums[k + 1]) {
				break;
			}
		}
		if (k < 0) {
			flg = 1;
			return;
		} 
        else {
			for (l = n - 1; l > k; l--) {
				if (nums[l] > nums[k]) {
					break;
				}
			}
			swap(nums[k], nums[l]);
			reverse(nums.begin() + k + 1, nums.end());
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>ans;
		sort(begin(nums), end(nums));
		int flg = 0;
		while (!flg) {
			ans.push_back(nums);
			nextPermutation(nums, flg);
		}
		return ans;
	}
};