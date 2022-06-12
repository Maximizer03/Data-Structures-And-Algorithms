class Solution {
public:
    int minSubArrayLen(int k, vector<int>& a) {
        int n = a.size();
        int sum = 0, ans = 1e9, l = 0, r = 0;
        while (r < n) {
            sum += a[r];
            if (sum >= k) {
                while (sum >= k) {
                    sum -= a[l];
                    l++;
                }
                ans = min(ans, r - l + 2);
            }
            r++;
        }
        if (ans == 1e9) {
            return 0;
        }
        return ans;
    }
};