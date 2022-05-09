class Solution {
public:
    vector<int>dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    string w;
	bool calc(int i, int j, int p, vector<vector<char>>& A, string &w) {
		int n = A.size(), m = A[0].size();
		if (i < 0 || j < 0 || i >= n || j >= m || A[i][j] != w[p]) {
			return false;
		}
		if (p == w.size()-1) {
			return true;
		}
		char c = A[i][j];
		A[i][j] = '0';
		for (int k = 0; k < 4; k++) {
			if (calc(i + dx[k], j + dy[k], p + 1, A, w)) {
				return true;
			}
		}
		A[i][j] = c;
		return false;
	}
	bool exist(vector<vector<char>>& A, string word) {
        w=word;
		int n = A.size(), m = A[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (calc(i, j, 0, A, w)) {
					return true;
				}
			}
		}
		return false;
	}
};