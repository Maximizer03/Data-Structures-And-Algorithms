class Solution {
public:
	int shortestPathLength(vector<vector<int>>& g) {
		int n = g.size();
        bool s[13][(1<<13)];
        memset(s,false,sizeof(s));
		queue<pair<int, int>>q;
		for (int i = 0; i < n; i++) {
			int mask = (1 << i);
			q.push({i, mask});
            s[i][mask]=true;
		}
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
					if (s[u][new_mask]==false) {
						q.push({u, new_mask});
                        s[u][new_mask]=true;
					}
				}
			}
			cnt++;
		}
		return -1;
	}
};