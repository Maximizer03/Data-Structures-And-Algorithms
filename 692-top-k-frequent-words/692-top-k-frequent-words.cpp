class Solution {
	struct cmp {
		bool operator()(const pair<int, string>&a, const pair<int, string>&b) {
			if (a.first != b.first) {
				return a.first > b.first;
			}
			else {
				return a.second < b.second;
			}
		}
	};
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string>res;
		unordered_map<string, int>m;
		for (string s : words) {
			m[s]++;
		}
		priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>q;
		for (auto &x : m) {
			q.push({x.second, x.first});
			if (q.size() > k) {
				q.pop();
			}
		}
		while (!q.empty()) {
			res.push_back(q.top().second);
			q.pop();
		}
		reverse(begin(res), end(res));
		return res;
	}
};