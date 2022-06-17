class Solution {
public:
    string originalDigits(string s) {
        int n = s.size();
        vector<string>st = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int>v = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        string ans = "";
        unordered_map<int, int>cnt;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < st.size(); i++) {
            string cur = st[i];
            unordered_map<int, int>f;
            for (int j = 0; j < cur.size(); j++) {
                f[cur[j] - 'a']++;
            }
            while (1) {
                bool flg = true;
                for (auto &x : f) {
                    if (cnt[x.first] < f[x.first]) {
                        flg = false; break;
                    }
                }
                if (flg == false) {
                    break;
                }
                for (auto &x : f) {
                    cnt[x.first] -= f[x.first];
                }
                char ch = v[i] + '0';
                ans += ch;
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};