class Solution {
public:
	int minOperations(vector<int>& arr) {
		int t = arr.size();
		set<int>s;
		for (int x : arr) {
			s.insert(x);
		}
		arr.clear();
		for (auto &x : s) {
			arr.push_back(x);
		}
		int n = arr.size();
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			int ub = upper_bound(begin(arr), end(arr), arr[i] + t - 1) - arr.begin();
			int de = ub - i;
			ans = min(ans, t - de);
		}
		return ans;
	}
};