class Solution {
public:
	int integerReplacement(int n) {
        using ll = long long;
		map<ll, ll>m;
		queue<pair<ll, ll>>q;
		q.push({n, 0});
		ll ans = -1;
		while (!q.empty()) {
			ll v = q.front().first;
			ll cnt = q.front().second;
			q.pop();
			if (v == 1) {
				return cnt;
			}
			if (v % 2 == 0) {

				if (m.find(v / 2) == m.end()) {
					m[v / 2] = cnt + 1;
					q.push({v / 2, cnt + 1});
				}
			}
			else {
				if (m.find(v + 1) == m.end()) {
					m[v + 1] = cnt + 1;
					q.push({v + 1, cnt + 1});
				}
				if (m.find(v - 1) == m.end()) {
					m[v - 1] = cnt + 1;
					q.push({v - 1, cnt + 1});
				}
			}
		}
		return ans;
	}
};