class Solution {
public:
    bool ispalind(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++; r--;
        }
        return true;
    }
    void calc(int i, string &s, int n, vector<string>cur, vector<vector<string>>&res) {
        if (i == n) {
            res.push_back(cur);
            return;
        }
        bool flg = false;
        for (int j = i; j < n; j++) {
            if (ispalind(s, i, j)) {
                flg = true;
                string x = s.substr(i, j - i + 1);
                cur.push_back(x);
                calc(j + 1, s, n, cur, res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>cur;
        int n = s.size();
        calc(0, s, n, cur, res);
        return res;
    }
};