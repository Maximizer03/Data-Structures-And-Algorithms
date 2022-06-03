class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>ans(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                swap(mat[i][j], ans[j][i]);
            }
        }
        return ans;
    }
};