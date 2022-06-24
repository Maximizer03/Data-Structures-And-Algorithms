class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<int>p = {1};
        for (int i = 2; i <= n; i++) {
            vector<int>v(i, 1);
            for (int j = 1; j < i - 1; j++) {
                v[j] = p[j] + p[j - 1];
            }
            p = v;
        }
        return p;
    }
};