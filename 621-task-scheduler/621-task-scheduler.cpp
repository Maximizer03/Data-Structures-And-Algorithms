class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int>cnt(26, 0);
		for (int i = 0; i < tasks.size(); i++) {
			cnt[tasks[i] - 'A']++;
		}
		priority_queue<int>pq;
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) {
				pq.push(cnt[i]);
			}
		}
		queue<pair<int, int>>q;
		int t = 0;
		while (1) {
			if (q.size() == 0 && pq.size() == 0) {
				break;
			}
			while (q.size() > 0 && q.front().second == t) {
				int f = q.front().first;
				q.pop();
				pq.push(f);
			}
			t++;
			if (!pq.empty()) {
				int e = pq.top();
				pq.pop();
				if (e - 1 > 0) {
					q.push({e - 1, n + t});
				}
			}
		}
		return t;
	}

};