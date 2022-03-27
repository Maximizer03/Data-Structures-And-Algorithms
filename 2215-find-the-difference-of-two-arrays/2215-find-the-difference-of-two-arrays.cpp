class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        vector<vector<int>>ans(2);
        unordered_set<int>sa(begin(A), end(A)), sb(begin(B), end(B));
        for (int x : sa) {
            if (sb.count(x) == 0) {
                ans[0].push_back(x);
            }
        }
        for (int x : sb) {
            if (sa.count(x) == 0) {
                ans[1].push_back(x);
            }
        }
        return ans;
    }
};