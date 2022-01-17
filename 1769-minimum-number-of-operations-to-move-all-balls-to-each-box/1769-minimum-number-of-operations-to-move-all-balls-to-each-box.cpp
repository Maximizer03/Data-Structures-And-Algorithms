class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector<int>ans(n, 0), dp1(n, 0), dp2(n, 0);
        // dp1[i]=>no of moves to move all boxes from left to ith box
        // dp1[i]=dp1[i-1]+cnt where cnt is number of boxes till now
        // dp2[i]=>no of moves to move all boxes from right to ith box
        // dp2[i]=dp2[i+1]+cnt where cnt= is number of boxes till now
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                dp1[i] = dp1[i - 1] + cnt;
            }
            if (s[i] == '1') {
                cnt++;
            }
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                dp2[i] = dp2[i + 1] + cnt;
            }
            if (s[i] == '1') {
                cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] = dp1[i] + dp2[i];
        }
        return ans;
    }
};