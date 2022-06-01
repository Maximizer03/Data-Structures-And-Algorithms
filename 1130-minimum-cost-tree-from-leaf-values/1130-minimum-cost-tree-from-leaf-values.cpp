class Solution {
public:
	int mctFromLeafValues(vector<int>& arr) {
		int n = arr.size();
		int ans = 0;
		vector<int>v;
		v.push_back(INT_MAX);
		for (int i = 0; i < n; i++) {
			while (arr[i] >= v.back()) {
				int x = v.back();
				v.pop_back();
				ans += min(v.back(), arr[i]) * x;
			}
			v.push_back(arr[i]);
		}
		for (int i = 2; i < v.size(); i++) {
			ans += v[i] * v[i - 1];
		}
		return ans;
	}
};