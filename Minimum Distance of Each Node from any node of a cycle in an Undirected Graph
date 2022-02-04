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

const int N = 2e5 + 5;

vector<int>g[N], par(N, -1), vis(N, 0), dist(N, 0);
int st = -1, en = -1;

bool cycleDfs(int v, int p) {
	par[v] = p;
	vis[v] = 1;
	for (auto &u : g[v]) {
		if (!vis[u]) {
			if (cycleDfs(u, v)) {
				return true;
			}
		}
		else if (u != p) {
			st = u;
			en = v;
			return true;
		}
	}
	return false;
}

void TEST_CASE() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>cyc;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (cycleDfs(i, -1)) {
				while (en != st) {
					cyc.push_back(en);
					en = par[en];
				}
				cyc.push_back(en);
				break;
			}
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	for (auto &x : cyc) {
		q.push(x);
		dist[x] = 0;
		vis[x] = 1;
	}
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int v = q.front();
			q.pop();
			for (auto &u : g[v]) {
				if (!vis[u]) {
					vis[u] = 1;
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
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
