class Solution {
public:
    bool calc(string &a, string &b) {
        int n = a.size(), m = b.size();
        int j = 0;
        for (int i = 0; i < n && j < m ; i++) {
            if (a[i] == b[j]) {
                j++;
            }
        }
        return (j >= m);
    }
    int findLUSlength(vector<string>& s) {
        map<string, int>m;
        for (auto &x : s) {
            m[x]++;
        }
        int n = s.size();
        int ans=-1;
        for (int i = 0; i < n; i++) {
            if (m[s[i]] == 1) {
                bool pos = true;
                for (int j = 0 ; j < n && j != i; j++) {
                    if (calc(s[j], s[i])) {
                        pos = false;
                        break;
                    }
                }
                if (pos == true) {
                    int len= s[i].size();
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};