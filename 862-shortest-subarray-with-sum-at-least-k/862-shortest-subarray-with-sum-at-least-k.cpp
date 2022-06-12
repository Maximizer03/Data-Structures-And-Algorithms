class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        deque<pair<int, long long>>d;
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum >= k) {
                ans = min(ans, i + 1);
            }
            int p = -1;
            while (!d.empty() && sum - d.front().second >= k) {
                p = d.front().first;
                d.pop_front();
            }
            if (p != -1) {
                ans = min(ans, i - p);
            }
            while (!d.empty() && d.back().second >= sum) {
                d.pop_back();
            }
            d.push_back({i, sum});
        }
        if (ans == 1e9) {
            return -1;
        }
        return ans;
    }
};