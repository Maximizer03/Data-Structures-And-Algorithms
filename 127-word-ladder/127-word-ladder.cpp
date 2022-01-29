class Solution {
public:
	void addNeighbours(string &w, unordered_set<string>&s, queue<string>&q) {
		for (int i = 0; i < w.size(); i++) {
			char c = w[i];
			for (char j = 'a'; j <= 'z'; j++) {
				if (w[i] == j) {
					continue;
				}
				w[i] = j;
				if (s.count(w)) {
					q.push(w);
					s.erase(w);
				}
			}
			w[i] = c;
		}
	}
	int ladderLength(string B, string E, vector<string>& A) {
		unordered_set<string>s(begin(A), end(A));
		if (s.count(E) == 0) {
			return 0;
		}
		queue<string>q;
		q.push(B);
		int ans = 1;
		while (q.size()) {
			int cnt = q.size();
			while (cnt--) {
				auto w = q.front();
				q.pop();
				if (w == E) {
					return ans;
				}
				addNeighbours(w, s, q);
			}
			ans++;
		}
		return 0;
	}
};