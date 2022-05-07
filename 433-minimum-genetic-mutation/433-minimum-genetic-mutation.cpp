class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		map<char, int>m;
		m['A'] = 1, m['C'] = 2, m['G'] = 3, m['T'] = 4;
		map<int, char>num;
		num[1] = 'A', num[2] = 'C', num[3] = 'G', num[4] = 'T';
		queue<string>q;
		set<string>pos;
		for (string k : bank) {
			pos.insert(k);
		}
		int steps = 0;
		q.push(start);
		set<string>used;
		used.insert(start);
		while (!q.empty()) {
			int si = q.size();
			for (int i = 0; i < si; i++) {
				string cur = q.front();
				q.pop();
				if (cur == end) {
					return steps;
				}
				for (int j = 0; j < cur.size(); j++) {
					int idx = m[cur[j]];
					for (int k = 1; k <= 4; k++) {
						if (k != idx) {
							char nw = num[k];
							string t = cur;
							t[j] = nw;
							if (used.find(t) == used.end() && pos.find(t) != pos.end()) {
								q.push(t);
								used.insert(t);
							}
						}
					}
				}
			}
			steps++;
		}
		return -1;
	}
};