class Solution {
public:
	int furthestBuilding(vector<int>& h, int B, int L) {
		int ans = 0;
		int n = h.size();
		priority_queue<int, vector<int>, greater<int>>q;
		long long sum = 0;
		for (int i = 1; i < n; i++) {
			if (h[i] > h[i - 1]) {
				q.push(h[i] - h[i - 1]);
			}
			if (q.size() > L) {
				sum += q.top();
				q.pop();
				if (sum > B) {
					return ans;
				}
			}
			ans = i;
		}
		return ans;
	}
};