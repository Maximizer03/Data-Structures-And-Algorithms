class Solution {
public:
	int threeSumClosest(vector<int>& a, int t) {
		sort(begin(a), end(a));
		int n = a.size();
		int ans = 0, diff = 1e9;
		for (int i = 0; i < n - 2; i++) {
			int l = i + 1, r = n - 1;
			int tar = t - a[i];
			while (l < r) {
				int sum = a[l] + a[r] + a[i];
				int d = abs(sum - t);
				if (d < diff) {
					diff = d;
					ans = sum;
				}
				if (a[l] + a[r] == tar) {
					break;
				}
				else if (a[l] + a[r] > tar) {
					r--;
				}
				else {
					l++;
				}
			}
		}
		return ans;
	}
};