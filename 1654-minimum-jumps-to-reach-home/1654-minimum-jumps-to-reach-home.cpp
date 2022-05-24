class Solution {
public:
	int minimumJumps(vector<int>& f, int a, int b, int x) {
		set<pair<int, int>>s;
		for (int i = 0; i < f.size(); i++) {
			s.insert({f[i], 0});
			s.insert({f[i], 1});
		}
		queue<pair<int, int>>q;
		q.push({0, 0});
		s.insert({0, 0});
		int steps = 0;
		while (!q.empty()) {
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int v = q.front().first, p = q.front().second;
				q.pop();
				if (v == x) {
					return steps;
				}
				int u = v + a;
				if (u >= 0 && u <= 10000 && s.find({u, 0}) == s.end()) {
					q.push({u, 0});
					s.insert({u, 0});
				}
				if (p == 0) {
					u = v - b;
					if (u >= 0 && u <= 10000 && s.find({u, 1}) == s.end()) {
						q.push({u, 1});
						s.insert({u, 1});
					}
				}
			}
			steps++;
		}
		return -1;
	}
};