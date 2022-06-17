class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& p) {
        sort(begin(p), end(p), [&](const vector<int>&a, const vector<int>&b) {
            return a[1]<b[1];
        });
        int n = p.size();
        int right = p[0][1];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (p[i][0] < right) {
                ans++;
            }
            else {
                right = p[i][1];
            }
        }
        return ans;
    }
};