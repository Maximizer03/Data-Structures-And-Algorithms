class Solution {
public:
	int calc(vector<int>&h) {
		int n = h.size();
		int area = 0;
		stack<pair<int, int>>st;
		vector<int>L(n, -1), R(n, n);
		for (int i = 0; i < n; i++) {
			while (!st.empty() && st.top().first >= h[i]) {
				st.pop();
			}
			if (!st.empty()) {
				L[i] = st.top().second;
			}
			st.push({h[i], i});
		}
		while (!st.empty()) {
			st.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && st.top().first >= h[i]) {
				st.pop();
			}
			if (!st.empty()) {
				R[i] = st.top().second;
			}
			st.push({h[i], i});
		}
		for (int i = 0; i < n; i++) {
			area = max(area, (R[i] - L[i] - 1) * h[i]);
		}
		return area;
	}
	int maximalRectangle(vector<vector<char>>& mat) {
		int n = mat.size(), m = mat[0].size();
		vector<vector<int>>dp(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0) {
					dp[i][j] = (mat[i][j] - '0');
				}
				else {
					if (mat[i][j] == '1') {
						dp[i][j] = 1;
						if (mat[i - 1][j] == '1') {
							dp[i][j] = 1 + dp[i - 1][j];
						}
					}
				}
			}
		}
		int area = 0;
		for (int i = 0; i < n; i++) {
			vector<int>h = dp[i];
			area = max(area, calc(h));
		}
		return area;

	}
};