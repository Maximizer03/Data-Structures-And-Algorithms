class Solution {
public:
    int calc(string &s, int n) {
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s1 = s.substr(0, i + 1);
            string s2 = s.substr(n - i - 1, i + 1);
            if (s1 == s2) {
                string t = "";
                for (int j = i + 1; j < n - i - 1; j++) {
                    t += s[j];
                }
                int d = 2;
                if (i == n - 1) {
                    d = 1;
                }
                ans = d + calc(t, t.size());
                break;
            }
        }
        return ans;
    }
    int longestDecomposition(string s) {
        int n = s.size();
        return calc(s, n);
    }
};