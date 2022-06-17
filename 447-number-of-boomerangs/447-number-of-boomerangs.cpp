class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = p[i][0], y = p[i][1];
            unordered_map<int, int>m;
            for (int j = 0; j < n; j++) {
                if (j == i)continue;
                int xx = p[j][0], yy = p[j][1];
                int dist = abs(xx - x) * abs(xx - x) + abs(yy - y) * abs(yy - y);
                m[dist]++;
            }
            for (auto &x : m) {
                int cnt = x.second;
                ans += (cnt * (cnt - 1));
            }
        }
        return ans;
    }
};