class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		priority_queue<array<int, 2>>q;
		for (int i = 0; i < arr.size(); i++) {
			q.push({abs(x - arr[i]), arr[i]});
			if (q.size() > k) {
				q.pop();
			}
		}
		vector<int>ans;
		while (!q.empty()) {
			ans.push_back(q.top()[1]);
			q.pop();
		}
		sort(begin(ans), end(ans));
		return ans;
	}
};