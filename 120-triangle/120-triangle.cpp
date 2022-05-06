class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n));
		vector<int>prev(n), cur(n);
		for (int i = 0; i < n; i++) {
			prev[i] = triangle[n - 1][i];
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				int op1 = prev[j];
				int op2 = (j + 1) ? prev[j + 1] : 1e8;
				int ans = triangle[i][j] + min(op1, op2);
				cur[j] = ans;
			}
			swap(prev, cur);
		}
		return prev[0];
	}
};