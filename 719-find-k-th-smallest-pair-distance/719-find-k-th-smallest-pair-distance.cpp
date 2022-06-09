class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        int n = a.size();
        sort(begin(a), end(a));
        int l = 0, r = a[n - 1] - a[0];
        int ans = r;
        while (l <= r) {
            int m = (l + r) / 2;
            int cnt = 0;
            int j = 0;
            for (int i = 0; i < n; i++) {
                while (j < n && a[j] - a[i] <= m) {
                    j++;
                }
                cnt += (j - i-1);
            }
            if (cnt >= k) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;

    }
};