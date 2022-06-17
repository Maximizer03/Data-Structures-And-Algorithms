class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>f(26, 0);
        int ans = 0, mx = 0, i = 0, j = 0;
        while (j < n) {
            int c = s[j] - 'A';
            f[c]++;
            mx = max(mx, f[c]);
            while (j - i + 1 - mx > k) {
                int l = s[i] - 'A';
                f[l]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};