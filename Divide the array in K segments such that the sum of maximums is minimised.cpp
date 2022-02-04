#include"bits/stdc++.h"
#define         int                 long long
#define         pb                  push_back
#define         fr                  first
#define         sc                  second
#define         pii                 pair<int,int>
#define         vi                  vector<int>
#define         mod                 1000000007
#define         sz(x)               (int)((x).size())
#define         all(x)              (x).begin(),(x).end()
#define         FOR(i,a,b)          for(int i=a;i<b;i++)
#define         INF                 3000000000000000000
#define         endl                "\n"
using namespace std;

const int N = 505;

int dp[N][N], a[N], n, k;

// dp[i][k]=> minimum sum of maximum from array left from [i......n-1] and partition left=k

int calc(int i, int cnt) {
	if (cnt == k) {
		if (i == n) {
			return 0;
		}
		else {
			return INF;
		}
	}
	if (i == n) {
		return INF;
	}
	if (dp[i][cnt] != -1) {
		return dp[i][cnt];
	}
	int ans = INF;
	int mx = a[i];
	for (int j = i; j < n; j++) {
		mx = max(mx, a[j]);
		ans = min(ans, calc(j + 1, cnt + 1) + mx);
	}
	return dp[i][cnt] = ans;
}

void TEST_CASE() {
	cin >> n >> k;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << calc(0, 0) << endl;
}

signed main() {
#ifndef UV3
	freopen("Error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		TEST_CASE();
	}
	return 0;
}
