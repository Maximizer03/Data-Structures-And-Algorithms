class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int f = 0, c = 0;
        for (int i = 0; i < n; i++) {
            f += gas[i];
            c += cost[i];
        }
        if (c > f) {
            return -1;
        }
        int s = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum < 0) {
                s = i;
                sum = 0;
            }
            sum += (gas[i] - cost[i]);
        }
        return s;
    }
};