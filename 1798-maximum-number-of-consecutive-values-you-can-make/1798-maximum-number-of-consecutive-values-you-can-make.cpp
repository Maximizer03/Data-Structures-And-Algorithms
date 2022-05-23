class Solution {
public:
	int getMaximumConsecutive(vector<int>& c) {
		int n = c.size();
		int mx = 0, ans = 1;
		sort(begin(c), end(c));
		for (int i = 0; i < n; i++) {
			if (c[i] > mx + 1) {
				return mx + 1;
			}
			else {
				mx += c[i];
			}
		}
		return mx + 1;
	}
};