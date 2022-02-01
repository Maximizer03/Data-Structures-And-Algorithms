class Solution {
public:
	int splitArray(vector<int>& a, int k) {
		int n = a.size();
		int r = 0, l = 0;
		for (auto &x : a) {
			l = max(l, x);
			r += x;
		}
		function<int(int)>calc = [&](int m) {
			int cnt = 1;
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += a[i];
				if (sum > m) {
					cnt++;
					sum = a[i];
					if (cnt > k) {
						return 0;
					}
				}
			}
			return 1;
		};
		int ans = INT_MAX;
		while (l <= r) {
			int m = (l + r) / 2;
			if (calc(m)) {
				ans = min(ans, m);
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		return ans;
	}
};