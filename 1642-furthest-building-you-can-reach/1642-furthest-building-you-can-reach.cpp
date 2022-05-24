class Solution {
public:
	int calc(int m, vector<int>&h, int B, int L) {
		vector<int>v;
		for (int i = 1; i <= m; i++) {
			if (h[i] > h[i - 1]) {
				v.push_back(h[i] - h[i - 1]);
			}
		}
		sort(begin(v), end(v));
		int s = v.size();
		while (v.size() > 0 && L > 0) {
			L--;
			v.pop_back();
		}
		if (v.size() == 0) {
			return 1;
		}
		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		return (long long)B >= sum;

	}
	int furthestBuilding(vector<int>& h, int B, int L) {
		int ans = 0;
        int n=h.size();
		int l = 1, r = n - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (calc(m, h, B, L)) {
				ans = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		return ans;
	}
};