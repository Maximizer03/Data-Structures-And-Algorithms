class Solution {
public:
	int ans;
	void calc(int i, int n, vector<int>&v) {
		if (i == n) {
			ans++;
			return;
		}
		for (int j = 0; j < n; j++) {
			if (v[j] == 0) {
				if ((j + 1) % (i + 1) == 0 || (i + 1) % (j + 1) == 0) {
					v[j] = 1;
					calc(i + 1, n, v);
					v[j] = 0;
				}
			}
		}
	}
	int countArrangement(int n) {
		vector<int>v(n, 0);
		ans = 0;
		calc(0, n, v);
		return ans;
	}
};