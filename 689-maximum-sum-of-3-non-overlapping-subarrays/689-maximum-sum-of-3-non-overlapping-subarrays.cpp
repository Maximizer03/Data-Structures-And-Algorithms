class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
		vector<int>res;
		for (int i = 0; i < 3; i++) {
			res.push_back(1e8);
		}
		int sum = 0;
		int n = a.size();
		vector<int>p(n);
		p[0] = a[0];
		for (int i = 1; i < n; i++) {
			p[i] = p[i - 1] + a[i];
		}
		vector<pair<int, int>>pref(n);
		pref[k - 1] = {0, p[k - 1]};
		for (int i = k; i < n; i++) {
			int cur_sum = p[i] - p[i - k];
			int cur_idx = i - k + 1;
			int prev_sum = pref[i - 1].second;
			int prev_idx = pref[i - 1].first;
			if (cur_sum > prev_sum) {
				pref[i] = {cur_idx, cur_sum};
			}
			else {
				pref[i] = pref[i - 1];
			}
		}
		vector<pair<int, int>>suff(n);
		suff[n - k] = {n - k, p[n - 1] - p[n - k - 1]};
		for (int i = n - k - 1; i > 0; i--) {
			int cur_sum = p[i + k - 1] - p[i - 1];
			int cur_idx = i;
			int prev_sum = suff[i + 1].second;
			int prev_idx = suff[i + 1].first;
			if (cur_sum >= prev_sum) {
				suff[i] = {cur_idx, cur_sum};
			}
			else {
				suff[i] = suff[i + 1];
			}
		}
		for (int i = k; i <= n - 2 * k; i++) {
			int cur = pref[i - 1].second + p[i + k - 1] - p[i - 1] + suff[i + k].second;
			vector<int>v;
			v.push_back(pref[i - 1].first);
			v.push_back(i);
			v.push_back(suff[i + k].first);
			if (cur > sum) {
				sum = cur;
				res = v;
			}
			else if (cur == sum) {
				if (v < res) {
					res = v;
				}
			}
		}
		return res;
	}
};