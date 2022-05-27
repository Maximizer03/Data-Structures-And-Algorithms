class Solution {
public:
	vector<long long >calc(vector<long long >&v) {
		long long  n = v.size();
		const int INF = 1e18;
		vector<long long > ans(n + 1, INF);
		vector<long long > vis(n + 1, 0);
		int k = n;
		vector<long long > a(k);
		for (int i = 0; i < k; i++) {
			a[i] = i;
		}
		// dijkstra
		priority_queue<pair<long long , long long >>q;
		for (int i = 0; i < n; i++) {
			ans[i] = v[i];
			q.push({v[i], i});
		}
		while (!q.empty()) {
			// (value,colno)
			int i = q.top().second;
			q.pop();
			if (vis[i]) {
				continue;
			}
			vis[i] = 1;
			if (i > 0) {
				if (ans[i] - 1 > ans[i - 1]) {
					ans[i - 1] = ans[i] - 1;
					q.push({ans[i - 1], i - 1});
				}
			}
			if (i < n - 1) {
				if (ans[i] - 1 > ans[i + 1]) {
					ans[i + 1] = ans[i] - 1;
					q.push({ans[i + 1], i + 1});
				}
			}
		}
		vector<long long >fnl;
		for (int i = 0; i < n; i++) {
			fnl.push_back(ans[i]);
		}
		return fnl;
	}
	long long maxPoints(vector<vector<int>>& A) {
		long long  n = A.size();
		long long  m = A[0].size();
		vector<vector<long long >>dp(n, vector<long long >(m));
		for (int i = 0; i < m; i++) {
			dp[0][i] = A[0][i];
		}
		for (int i = 1; i < n; i++) {
			vector<long long >v;
			for (int j = 0; j < m; j++) {
				v.push_back(dp[i - 1][j]);
			}
			vector<long long >ans = calc(v);
			for (int j = 0; j < m; j++) {
				dp[i][j] = A[i][j] + ans[j];
			}
		}
		long long mx = 0;
		for (int i = 0; i < m; i++) {
			mx = max(mx, dp[n - 1][i]);
		}
		return mx;
	}
};
