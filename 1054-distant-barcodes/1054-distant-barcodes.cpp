class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& b) {
		unordered_map<int, int>m;
		int n = b.size();
		for (int i = 0; i < n; i++) {
			m[b[i]]++;
		}
		priority_queue<pair<int, int>>q;
		for (auto &x : m) {
			q.push({x.second, x.first});
		}
		vector<int>ans;
		while (!q.empty()) {
			int cnt = q.top().first;
			int c1 = q.top().second;
			q.pop();
			if (ans.size() > 0 && ans.back() == c1) {
				int cnt2 = q.top().first;
				int c2 = q.top().second;
				q.pop();
				q.push({cnt, c1});
				cnt2--;
				ans.push_back(c2);
				if (cnt2) {
					q.push({cnt2, c2});
				}
			}
			else {
				cnt--;
				ans.push_back(c1);
				if (cnt) {
					q.push({cnt, c1});
				}
			}
		}
		return ans;
	}
};