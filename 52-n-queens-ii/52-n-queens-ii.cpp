class Solution {
public:
    int cnt;
	void solve(int col, int n, vector<string>&cur, vector<int>&LR, vector<int>&LD, vector<int>&UD) {
		if (col == n) {
			cnt++;
			return;
		}
		for (int row = 0; row < n; row++) {
			if (LR[row] == 0 && LD[row + col] == 0 && UD[n - 1 + col - row] == 0) {
				cur[row][col] = 'Q';
				LR[row] = 1 ,LD[row + col] = 1 ,UD[n - 1 + col - row] = 1;
				solve(col + 1, n, cur,  LR, LD, UD);
				LR[row] = 0 ,LD[row + col] = 0 ,UD[n - 1 + col - row] = 0;
				cur[row][col] = '.';
			}
        }
    }
	int totalNQueens(int n) {
		string t = string(n, '.');
		vector<string>cur(n, t);
        cnt=0;
        vector<int>LR(n),LD(2*n),UD(2*n);
		solve(0, n, cur,LR,LD,UD);
		return cnt;
	}
};