#define ll long long

class Solution {
public:
	vector<vector<vector<ll>>>dp;
	vector<int>group;
	vector<int>profit;
	long long mod = 1e9 + 7;
	ll calc(ll m, ll P, ll n) {
		if (m == 0) {
			return P <= 0;
		}
		if (P < 0) {
			P = 0;
		}
		if (dp[m][P][n] != -1) {
			return dp[m][P][n];
		}
		ll ans = calc(m - 1, P, n);
		if (n >= group[m - 1]) {
			ans = (ans + calc(m - 1, P - profit[m - 1], n - group[m - 1]) ) % mod;
		}
		return dp[m][P][n] = ans;
	}
	int profitableSchemes(int n, int P, vector<int>& g, vector<int>& pr) {
		int m = g.size();
		group = g;
		profit = pr;
		dp = vector<vector<vector<ll>>>(m + 1, vector<vector<ll>>(P + 1, vector<ll>(n + 1, -1)));
		return calc(m, P, n) % mod;

	}
};