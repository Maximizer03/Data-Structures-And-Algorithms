class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>res;
        for (auto &p : queries) {
            int r = p[2], cnt = 0;
            for (auto &q : points) {
                cnt += ((q[1] - p[1]) * (q[1] - p[1]) +  (q[0] - p[0]) * (q[0] - p[0])) <= r * r;
            }
            res.push_back(cnt);
        }
        return res;
    }
};