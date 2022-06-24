class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int>dp(n);
        vector<int>ans(26, 0);
        int cnt = 1;
        int i = 1;
        for (i = 1; i < n; i++) {
            int n1 = s[i - 1] - 'a', n2 = s[i] - 'a';
            if ((n1 + 1) % 26 == n2) {
                cnt++;
            }
            else {
                int v = cnt;
                for (int j = i - cnt; j < i; j++) {
                    int idx = s[j] - 'a';
                    dp[j] = v;
                    ans[idx] = max(ans[idx], v);
                    v--;
                }
                cnt = 1;
            }
        }
        int v = cnt;
        for (int j = i - cnt; j < i; j++) {
            int idx = s[j] - 'a';
            dp[j] = v;
            ans[idx] = max(ans[idx], v);
            v--;
        }
        int f = 0;
        for (int i = 0; i < 26; i++) {
            f += ans[i];
        }
        return f;
    }
};