class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>>ans;
		map<int, int>m;
		for (int i = 0; i < (1 << n); i++) {
			int cnt = 0;
			vector<int>v;
			for (int j = 0; j < n; j++) {
				int bit = (1 << j)&i;
				if (bit) {
					cnt++;
					v.push_back(j + 1);
				}
			}
			if (cnt == k && m.find(i) == m.end()) {
				ans.push_back(v);
				m[i]++;
			}
		}
		return ans;
	}
};