class Solution {
public:
	int dp[50005];
	int calc(int i, vector<int>&nxt, vector<int>& s, vector<int>& e, vector<int>& p) {
		int n = s.size();
		if (i >= n) {
			return 0;
		}
		if (dp[i] != -1) {
			return dp[i];
		}
		int ans = calc(i + 1, nxt, s, e, p);
		ans = max(ans, calc(nxt[i], nxt, s, e, p) + p[i]);
		return dp[i] = ans;
	}
	int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
		vector<pair<int, pair<int, int>>>pr;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			pr.push_back({s[i], {e[i], p[i]}});
		}
		sort(begin(pr), end(pr));
		for (int i = 0; i < n; i++) {
			s[i] = pr[i].first;
			e[i] = pr[i].second.first;
			p[i] = pr[i].second.second;
		}
		vector<int>nxt(n);
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int l = lower_bound(begin(s), end(s), e[i]) - s.begin();
			nxt[i] = max(i + 1, l);
		}
		return calc(0, nxt, s, e, p);
	}
};