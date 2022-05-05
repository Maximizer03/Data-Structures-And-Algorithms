class Solution {
public:
	int maxProfit(int K, vector<int>& p) {
		int n = p.size();
		vector<vector<long long>>prev(2, vector<long long>(K + 1, 0));
		vector<vector<long long>>cur(2, vector<long long>(K + 1, 0));
		for (int i = n - 1; i >= 0; i--) {
			for (int b = 0; b <= 1; b++) {
				for (int k = 0; k <= K; k++) {
					long long ans = 0;
					if (!b) {
						ans = prev[b][k];
						ans = max(ans, prev[1][k] - p[i]);
					}
					else {
						ans = prev[b][k];
						if (k > 0) {
							ans = max(ans, prev[0][k - 1] + p[i]);
						}
					}
					cur[b][k] = ans;
				}
			}
			swap(prev, cur);
		}
		return prev[0][K];
	}
};