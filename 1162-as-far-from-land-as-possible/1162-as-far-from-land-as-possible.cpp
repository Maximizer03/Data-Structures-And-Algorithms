class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>>d(n, vector<int>(n, 1e9));
        vector<vector<int>>vis(n, vector<int>(n, 0));
        queue<pair<int, int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    q.push({i, j});
                    d[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};
        int ans = -1;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < n && vis[xx][yy] == 0) {
                        vis[xx][yy] = 1;
                        d[xx][yy] = d[x][y] + 1;
                        q.push({xx, yy});
                        ans = max(ans, d[xx][yy]);
                    }
                }
            }
        }
        return ans;
    }
};