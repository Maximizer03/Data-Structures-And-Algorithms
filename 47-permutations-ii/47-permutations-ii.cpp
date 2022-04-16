class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>>ans;
		sort(begin(nums), end(nums));
		do {
			if (ans.size()) {
				if (nums != ans.back()) {
					ans.push_back(nums);
				}
			}
			else {
				ans.push_back(nums);
			}
		} while (next_permutation(begin(nums), end(nums)));
		return ans;
	}
};