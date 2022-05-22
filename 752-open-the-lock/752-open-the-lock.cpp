class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string>s;
		string cur = "0000";
		for (auto &x : deadends) {
			s.insert(x);
		}
		int steps = 0;
		queue<string>q;
		if (s.find(cur) != s.end()) {
			return -1;
		}
		q.push(cur);
		s.insert(cur);
		while (!q.empty()) {
			int si = q.size();
			while (si--) {
				string v = q.front();
				q.pop();
				if (v == target) {
					return steps;
				}
				for (int i = 0; i < 4; i++) {
                    char org= v[i];
					int d = v[i] - '0';
					int nxt = (d + 1) % 10;
					int prev = (d - 1 + 10) % 10;
					char nn = nxt + '0';
					char pp = prev + '0';
					v[i] = nn;
					if (s.find(v) == s.end()) {
						q.push(v);
						s.insert(v);
					}
					v[i] = pp;
					if (s.find(v) == s.end()) {
						q.push(v);
						s.insert(v);
					}
                    v[i]=org;
				}
			}
			steps++;
		}
		return -1;
	}
};