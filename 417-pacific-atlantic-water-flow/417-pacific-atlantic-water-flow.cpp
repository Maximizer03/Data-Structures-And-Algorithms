class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        int vis[n][m];
        memset(vis,false,sizeof(vis));
        queue<pair<int, int>>q;
        vector<vector<int>>cnt(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    cnt[i][j]++;
                }
            }
        }
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && h[x][y]<=h[xx][yy] && vis[xx][yy] == 0) {
                        vis[xx][yy] = 1;
                        cnt[xx][yy]++;
                        q.push({xx, yy});
                    }
                }
            }
        }
        memset(vis,false,sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n - 1 || j == m - 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    cnt[i][j]++;
                }
            }
        }
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && h[x][y]<=h[xx][yy] && vis[xx][yy] == 0) {
                        vis[xx][yy] = 1;
                        cnt[xx][yy]++;
                        q.push({xx, yy});
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cnt[i][j] == 2) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};