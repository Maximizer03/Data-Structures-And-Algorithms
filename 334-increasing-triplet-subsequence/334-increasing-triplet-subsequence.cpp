class Solution {
public:
	bool increasingTriplet(vector<int>& a) {
		int n = a.size();
		vector<int>mn(n), mx(n);
		mn[0] = a[0];
		for (int i = 1; i < n; i++) {
			mn[i] = min(mn[i - 1], a[i]);
		}
		mx[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			mx[i] = max(mx[i + 1], a[i]);
		}
		for (int i = 1; i < n - 1; i++) {
			if (mn[i - 1] < a[i] && mx[i + 1] > a[i]) {
				return true;
			}
		}
		return false;
	}
};