class Solution {
public:
	vector<int> countPairs(int n, vector<vector<int>>& e, vector<int>& q) {
		vector<int>deg(n, 0);
		vector<int>res, v;
		map<pair<int, int>, int>mp;
		for (auto it : e) {
			int u = it[0] - 1;
			int v = it[1] - 1;
			if (u > v) {
				swap(u, v);
			}
			mp[ {u, v}]++;
			deg[u]++; deg[v]++;
		}
		for (int i = 0; i < n; i++) {
			v.push_back(deg[i]);
		}
		sort(begin(v), end(v));
		for (auto it : q) {
			int k = it;
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				int j = lower_bound(v.begin(), v.end(), k + 1 - v[i]) - v.begin();
				cnt += n - max(j, i + 1);
			}
			for (auto it2 : mp) {
				int u = it2.first.first;
				int v = it2.first.second;
				int val = it2.second;
				if (deg[u] + deg[v] > k && deg[u] + deg[v] - val <= k) {
					cnt--;
				}
			}
			res.push_back(cnt);
		}
		return res;
	}
};