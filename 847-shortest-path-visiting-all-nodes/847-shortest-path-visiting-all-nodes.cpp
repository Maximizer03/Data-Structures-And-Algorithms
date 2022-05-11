class Solution {
public:
	int get(int v, vector<vector<int>>&g) {
		int n = g.size();
		set<pair<int, int>>s;
		queue<pair<int, int>>q;
		int mask = (1 << v);
		q.push({v, mask});
		s.insert({v, mask});
		int cnt = 0;
		while (q.size() > 0) {
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int v = q.front().first;
				int mask = q.front().second;
				if (mask == (1 << n) - 1) {
					return cnt;
				}
				q.pop();
				for (auto &u : g[v]) {
					int new_mask =  mask | (1 << u);
					if (s.find({u, new_mask}) == s.end()) {
						q.push({u, new_mask});
						s.insert({u, new_mask});
					}
				}
			}
			cnt++;
		}
		return -1;
	}
	int shortestPathLength(vector<vector<int>>& g) {
		int n = g.size();
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			ans = min(ans, get(i, g));
		}
		return ans;
	}
};