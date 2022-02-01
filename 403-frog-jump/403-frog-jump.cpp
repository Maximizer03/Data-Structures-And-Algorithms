class Solution {
public:
	bool canCross(vector<int>& a) {
		int n = a.size();
		map<int, set<int>>m;
		m[0].insert(1);
		for (int i = 0; i < n; i++) {
			for (auto &x : m[a[i]]) {
				int next = x + a[i];
				if (binary_search(a.begin(), a.end(), next)) {
					for (int j = x - 1; j <= x + 1; j++) {
						if (j > 0) {
							m[next].insert(j);
						}
					}
				}
			}
		}
		return (m[a[n-1]].size());
	}
};