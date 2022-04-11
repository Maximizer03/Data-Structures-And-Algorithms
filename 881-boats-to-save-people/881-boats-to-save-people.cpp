class Solution {
public:
	int numRescueBoats(vector<int>& P, int L) {
		int n = P.size();
		sort(begin(P), end(P));
		int ans = 0;
		int l = 0, r = n - 1;
		while (l < r) {
			int sum = P[l] + P[r];
			if (sum > L) {
				ans++;
				r--;
			}
			else {
				l++;
				r--;
				ans++;
			}
		}
		if (l == r) {
			ans++;
		}
		return ans;
	}
};