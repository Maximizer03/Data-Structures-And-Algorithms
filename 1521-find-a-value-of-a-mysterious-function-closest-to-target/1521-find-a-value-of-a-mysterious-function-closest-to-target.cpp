class Solution {
public:
    int closestToTarget(vector<int>& arr, int T) {
        int n = arr.size();
        unordered_set<int>c;
        int ans = 2e9;
        for (int i = 0; i < n; i++) {
            unordered_set<int>t;
            t.insert(arr[i]);
            for (auto &x : c) {
                t.insert((x & arr[i]));
            }
            swap(c, t);
            for (auto &x : c) {
                ans = min(ans, abs(x - T));
            }
        }
        return ans;
    }
};