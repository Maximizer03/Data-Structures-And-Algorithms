class Solution {
	struct cmp {
		bool operator()(const array<int, 3>&a, const array<int, 3>&b) {
			return a[0] < b[0];
		}
	};
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue<array<int, 3>, vector<array<int, 3>>, cmp>q;
		vector<vector<int>>res;
		for (vector<int> v : points) {
			int x = v[0], y = v[1];
			int dist = x * x + y * y;
			q.push({dist, x, y});
			if (q.size() > k) {
				q.pop();
			}
		}
		while (!q.empty()) {
			int x = q.top()[1], y = q.top()[2];
			q.pop();
			res.push_back({x, y});
		}
		reverse(begin(res), end(res));
		return res;
	}
};