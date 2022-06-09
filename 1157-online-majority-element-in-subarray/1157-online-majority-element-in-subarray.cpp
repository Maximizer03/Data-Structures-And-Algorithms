class MajorityChecker {
public:
    unordered_map<int, vector<int>>m;
    vector<int>v;
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        v.resize(n);
        v = arr;
    }
    int query(int L, int R, int T) {
        for (int i = 0; i < 10; i++) {
            int cnt = rand() % (R - L + 1);
            int j = v[L + cnt];
            if (m[j].size() < T) {
                continue;
            }
            int ans = upper_bound(begin(m[j]), end(m[j]), R) - lower_bound(begin(m[j]), end(m[j]), L);
            if (ans >= T) {
                return j;
            }
        }
        return -1;
    }
};
