class Solution {
public:
	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		int n = mat.size(), m = mat[0].size();
		bitset < 70 * 70 + 1 > b;
		for (int i = 0; i < m; i++) {
			b[mat[0][i]] = true;
		}
		for (int i = 1; i < n; i++) {
			bitset<4901>c;
			for (auto &x : unordered_set(begin(mat[i]), end(mat[i]))) {
				c = c | (b << x);
			}
			b = c;
		}
		int ans = 1e9;
		for (int i = 0; i < 4901; i++) {
			if (b[i] == true) {
				ans = min(ans, abs(target - i));
			}
		}
		return ans;
	}
};