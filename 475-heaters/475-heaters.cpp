class Solution {
public:
	bool calc(int r, vector<int>&hs, vector<int>&h) {
		int n = hs.size();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x = hs[i];
			bool flg = 0;
			int l = lower_bound(begin(h), end(h), x) - h.begin();
			if (l == h.size()) {
				l--;
			}
			if (abs(h[l] - x) <= r) {
				flg = 1;
			}
			if (l + 1 < h.size()) {
				l++;
			}
			if (abs(h[l] - x) <= r) {
				flg = 1;
			}
			if (l > 0) {
				l--;
			}
			if (abs(h[l] - x) <= r) {
				flg = 1;
			}
			if (l > 0) {
				l--;
			}
			if (abs(h[l] - x) <= r) {
				flg = 1;
			}
			if (flg) {
				cnt++;
			}
		}
		return (cnt == n);
	}
	int findRadius(vector<int>& hs, vector<int>& h) {
		int l = 0, r = 1e9;
		int ans = 1e9;
		sort(begin(hs), end(hs));
		sort(begin(h), end(h));
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (calc(mid, hs, h)) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return ans;
	}
};