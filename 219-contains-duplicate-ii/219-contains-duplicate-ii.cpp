class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, vector<int>>m;
		int cnt = 0;
		for (int i : nums) {
			m[i].push_back(cnt);
			cnt++;
		}
		for (auto &x : m) {
			vector<int>vec = x.second;
			if (vec.size() > 1) {
				for (int j = 1; j < vec.size(); j++) {
					if (vec[j] - vec[j - 1] <= k) {
						return true;
					}
				}
			}
		}
		return false;
	}
};