class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -1e9, n = nums.size(), p = -1e9, c;
        for (int i = 0; i < n; i++) {
            c = nums[i];
            if (i) {
                c = max(c, c + p);
            }
            mx = max(mx, c);
            p = c;
        }
        return mx;
    }
};