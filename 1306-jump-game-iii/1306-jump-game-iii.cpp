class Solution {
public:
	bool canReach(vector<int>& arr, int st) {
		int n = arr.size();
		vector<bool>vis(n);
		vis[st] = 1;
		if (arr[st] == 0) {
			return true;
		}
		queue<int>q;
		q.push(st);
		while (!q.empty()) {
			int s = q.size();
			while (s--) {
				int v = q.front();
				q.pop();
				if (arr[v] == 0) {
					return true;
				}
				if (v + arr[v] < n && vis[v + arr[v]] == 0) {
					vis[v + arr[v]] = 1;
					q.push(v + arr[v]);
				}
				if (v - arr[v] >= 0 && vis[v - arr[v]] == 0) {
					q.push(v - arr[v]);
					vis[v - arr[v]] = 1;
				}
			}
		}
		return false;
	}
};