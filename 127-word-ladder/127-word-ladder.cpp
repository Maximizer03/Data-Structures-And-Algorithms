class Solution {
public:
	int ladderLength(string B, string E, vector<string>& words) {
		set<string>s;
		map<string, int>vis, dist;
		map<string, set<string>>par, g;
		for (string k : words) {
			s.insert(k);
		}
		s.insert(B);
		for (auto &x : s) {
			string cur = x;
			for (int i = 0; i < cur.size(); i++) {
				char org = cur[i];
				for (char ch = 'a'; ch <= 'z'; ch++) {
					if (ch == org) {
						continue;
					}
					cur[i] = ch;
					if (s.find(cur) != s.end()) {
						g[x].insert(cur);
					}
					cur[i] = org;
				}
			}
		}
		queue<string>q;
		par[B].insert("*");
		vis[B] = 1;
		q.push(B);
		dist[B] = 1;
		while (!q.empty()) {
			string v = q.front();
			q.pop();
			if (v == E) {
				return dist[v];
			}
			for (auto &u : g[v]) {
				if (!vis.count(u)) {
					par[u].insert(v);
					vis[u] = 1;
					dist[u] = dist[v] + 1;
					q.push(u);
				}
				else if (dist[u] == dist[v] + 1) {
					par[u].insert(v);
				}
			}
		}
		return dist[E];
	}
};