class Solution {
public:
    int calc(int mid, int mx, int ind, int n) {
        int L = ind, R = n - ind - 1;
        long long lc = ind - max(0, ind - mid + 1) + 1;
        long long rc = min(n - 1, mid + ind - 1) - ind + 1;
        lc = max(0LL, lc - 1);
        rc = max(0LL, rc - 1);
        long long sum = (1 + lc + rc) * (long long)mid;
        sum -= (lc) * (lc + 1) / 2;
        sum -= (rc) * (rc + 1) / 2;
        // cout<<lc<<" "<<rc<<" "<<ind<<" "<<sum<<" "<<mid<<endl;
        return (sum <= mx);
        
    }
    int maxValue(int n, int ind, int mx) {
        mx -= n;
        int l = 0, r = mx;
        int ans = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (calc(m, mx, ind, n)) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans + 1;
    }
};