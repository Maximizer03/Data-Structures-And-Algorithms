class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<int>dx = {1, 1, 1, -1, -1, -1, 0, 0};
        vector<int>dy = { -1, 0, 1, -1, 0, 1, -1, 1};
        int xc = king[0], yc = king[1];
        vector<vector<bool>>arr(8, vector<bool>(8));
        for (int i = 0; i < queens.size(); i++) {
            arr[queens[i][0]][queens[i][1]] = true;
        }
        vector<vector<int>>res;
        for (int k = 0; k < 8; k++) {
            int x = xc, y = yc;
            while (x >= 0 && x < 8 && y >= 0 && y < 8 && arr[x][y] == false) {
                x = x + dx[k];
                y = y + dy[k];
            }
            if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                res.push_back({x, y});
            }
        }
        return res;
    }
};