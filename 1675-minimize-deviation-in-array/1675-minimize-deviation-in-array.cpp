class Solution {
public:
    int minimumDeviation(vector<int>& arr) {
        priority_queue<int>q;
        int n = arr.size();
        int mn = 2e9 + 3;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 1) {
                arr[i] *= 2;
            }
            mn = min(mn, arr[i]);
            q.push(arr[i]);
        }
        int diff = 2e9 + 5;
        while (q.top() % 2 == 0) {
            int v = q.top();
            q.pop();
            diff = min(diff, v - mn);
            mn = min(mn, v / 2);
            q.push(v / 2);
        }
        diff = min(diff, q.top() - mn);
        return diff;
    }
};