class Solution {
public:
	int findMaxLength(vector<int>& arr) {
		int n = arr.size();
		int z = 0, o = 0;
		unordered_map<int, int>m;
		m[0] = -1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				z++;
			}
			else if (arr[i] == 1) {
				o++;
			}
			int d = o - z;
			if (m.count(d)) {
				ans = max(ans, i - m[d]);
			}
			else {
				m[d] = i;
			}
		}
		return ans;
	}
};