class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size();
        if (n == 1) {
            return 0;
        }
        int l = 0, r = n - 1;
        while (l < n - 1 && a[l] <= a[l + 1]) {
            l++;
        }
        while (r > 0 && a[r] >= a[r - 1]) {
            r--;
        }
        if (l > r) {
            return 0;
        }
        int mn = 1e9, mx = -1e9;
        for (int i = l; i <= r; i++) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        l--;
        r++;
        while (l >= 0 && a[l] > mn) {
            l--;
        }
        while (r < n && a[r] < mx) {
            r++;
        }
        return (r - l - 1);
    }
};