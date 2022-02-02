class Solution {
public:
	vector<int> maxScoreIndices(vector<int>& nums) {
		int n = nums.size();
		vector<int>a(n + 2, 0);
		for (int i = 0; i < n; i++) {
			a[i + 1] = nums[i];
		}
		vector<int>p(n + 2, 0), s(n + 2, 0);
		for (int i = 1; i <= n; i++) {
			p[i] = p[i - 1] + (a[i] == 0);
		}
		for (int i = n; i >= 1; i--) {
			s[i] = s[i + 1] + (a[i] == 1);
		}
		int mx = 0;
		for (int i = 1; i <= n + 1; i++) {
			mx = max(mx, s[i] + p[i - 1]);
		}
		vector<int>ans;
		for (int i = 1; i <= n + 1; i++) {
			if (mx == p[i - 1] + s[i]) {
				ans.push_back(i - 1);
			}
		}
		return ans;
	}
};