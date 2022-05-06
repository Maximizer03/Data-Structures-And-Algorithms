class Solution {
    int findDup(string &s, int len) {
        unordered_set<unsigned long long> st;
        unsigned long long d = 16777619, h = 0, p = 1;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i];
            if (i < len) p *= d;
            else h -= s[i - len] * p;
            if (i >= len - 1) {
                if (st.count(h)) return i - len + 1;
                st.insert(h);
            }
        }
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        int L = 0, R = s.size() - 1, start = 0;
        while (L < R) {
            int M = (L + R + 1) / 2, i = findDup(s, M);
            if (i != -1) {
                L = M;
                start = i;
            } else R = M - 1;
        }
        return s.substr(start, L);
    }
};