class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        vector<pair<int, int>>p;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            p.push_back({v[i], i});
        }
        sort(begin(p), end(p));
        vector<vector<int>>ans;
        int i = 0;
        for (i = 0; i < n;) {
            vector<int>k;
            int s = p[i].first;
            for (int j = i; j < i + s; j++) {
                k.push_back(p[j].second);
            }
            ans.push_back(k);
            i += s;
        }
        return ans;
    }
};