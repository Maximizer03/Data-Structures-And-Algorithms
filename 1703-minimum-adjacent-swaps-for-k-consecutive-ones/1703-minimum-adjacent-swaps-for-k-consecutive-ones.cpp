class Solution {
public:
    vector<long long>p;
    int calc(int l, int r) {
        if (l > r) {
            return 0;
        }
        int ans = p[r];
        if (l) {
            ans -= p[l - 1];
        }
        return ans;
    }
    int minMoves(vector<int>& arr, int k) {
        vector<int>v;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                v.push_back(i);
            }
        }
        int n = v.size();
        p.resize(n);
        p[0] = v[0];
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] + v[i];
        }
        long long ans = 1e9;
        for (int i = 0; i + k <= n; i++) {
            int l = i, r = i + k - 1;
            int mid = l + (k - 1) / 2;
            long long R = calc(mid + 1, r);
            long long L = calc(l, mid - 1);
            long long tot = R - L;
            long long rad = (k - 1) / 2;
            tot -= rad * (rad + 1);
            if (k % 2 == 0) {
                tot -= v[mid];
                tot -= (rad + 1);
            }
            ans = min(ans, tot);
        }
        return (int)ans;
    }
};