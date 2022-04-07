class Solution {
public:
	int slidingPuzzle(vector<vector<int>>& mat) {
		string tar = "123450";
		string cur = "";
		unordered_map<string, int>m;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				char ch = mat[i][j] + '0';
				cur += ch;
			}
		}
		vector<int>dx = {1, -1, 0, 0};
		vector<int>dy = {0, 0, 1, -1};
		queue<pair<string, int>>q;
		q.push({cur, 0});
		m[cur]++;
		while (!q.empty()) {
			string v = q.front().first;
			int moves = q.front().second;
			q.pop();
			if (v == tar) {
				return moves;
			}
			int num = -1;
			for (int i = 0; i < 6; i++) {
				if (v[i] == '0') {
					num = i;
				}
			}
			int x = num / 3, y = num % 3;
			for (int j = 0; j < 4; j++) {
				int xx = x + dx[j];
				int yy = y + dy[j];
				if (xx >= 0 && xx <= 1 && yy >= 0 && yy <= 2) {
					string u = v;
					int pos = xx * 3 + yy;
					swap(u[pos], u[num]);
					if (m.find(u) == m.end()) {
						q.push({u, moves + 1});
						m[u]++;
					}
				}
			}
		}
		return -1;
	}
};