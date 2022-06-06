class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    int countDifferentSubsequenceGCDs(vector<int>& a) {
        int n = a.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
        }
        vector<bool>m(mx + 1);
        for (int i = 0; i < n; i++) {
            m[a[i]] = true;
        }
        int cnt = 0;
        for (int i = 1; i <= mx; i++) {
            int g = 0;
            for (int j = i; j <= mx; j += i) {
                if (m[j]) {
                    g = gcd(g, j);
                }
                if (g == i) {
                    break;
                }
            }
            if (g == i) {
                cnt++;
            }
        }
        return cnt;
    }
};