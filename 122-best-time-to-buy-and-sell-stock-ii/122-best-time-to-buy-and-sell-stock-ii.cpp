class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int>prev(2, 0), cur(2, 0);
		prev[0] = prev[1] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int cnt = 0; cnt <= 1; cnt++) {
				int ans = 0;
				if (cnt == 0) {
					ans = max(prev[0], prev[1] - prices[i]);
				}
				else {
					ans = max(prev[1], prev[0] + prices[i]);
				}
				cur[cnt] = ans;
			}
			swap(cur, prev);
		}
		return prev[0];
	}
};