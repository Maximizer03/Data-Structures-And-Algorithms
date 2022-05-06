class Solution {
public:
	void calc(int i, vector<int>cur, vector<vector<int>>&res, int target, vector<int>&c) {
		if (i == c.size()) {
			if (target == 0) {
				res.push_back(cur);
			}
			return;
		}
		if (target < 0) {
			return;
		}
		if (target == 0) {
			res.push_back(cur);
			return;
		}
		cur.push_back(c[i]);
		calc(i + 1, cur, res, target - c[i], c);
		cur.pop_back();
		int j = i, n = c.size();
		while (j < n && c[j] == c[i]) {
			j++;
		}
		calc(j, cur, res, target, c);
	}
	vector<vector<int>> combinationSum2(vector<int>& c, int target) {
		vector<vector<int>>res;
		vector<int>cur;
		sort(begin(c), end(c));
		calc(0, cur, res, target, c);
		return res;
	}
};