class Solution {
public:
	int minimumDifference(vector<int>& v) {
		int N = v.size();
		int n = N / 2;
		sort(begin(v), end(v));
		vector<int>v1, v2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += v[i];
			if (i < n) {
				v1.push_back(v[i]);
			}
			else {
				v2.push_back(v[i]);
			}
		}
		vector<set<int>>s1(n + 1), s2(n + 1);
		for (int m = 0; m < (1 << n); m++) {
			int sum1 = 0, sum2 = 0;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				int bit = (1 << j)&m;
				if (bit > 0) {
					sum1 += v1[j];
					sum2 += v2[j];
					cnt++;
				}
			}
			s1[cnt].insert(sum1);
			s2[cnt].insert(sum2);
		}
		vector<vector<int>>a1(n + 1), a2(n + 1);
		for (int i = 0; i <= n; i++) {
			for (auto &x : s1[i]) {
				a1[i].push_back(x);
			}
			for (auto &y : s2[i]) {
				a2[i].push_back(y);
			}
		}
		int ans = 1e9;
		int tar = sum / 2;
		for (int i = 0; i <= n; i++) {
			for (int k = 0; k < a1[i].size(); k++) {
					int cur = a1[i][k];
					int l = lower_bound(begin(a2[n - i]), end(a2[n - i]), tar - cur) - begin(a2[n - i]);
					if (l == a2[n - i].size()) {
						l--;
					}
					int summ = cur + a2[n - i][l];
					int rem = sum - summ;
					ans = min(ans, abs(summ - rem));
					if (l > 0) {
						l--;
					}
					summ = cur + a2[n - i][l];
					rem = sum - summ;
					ans = min(ans, abs(summ - rem));
			}
		}
		return ans;
	}
};