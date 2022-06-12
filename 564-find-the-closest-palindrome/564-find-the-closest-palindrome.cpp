#define lli long long int
class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.size();
        vector<long long>p;
        lli v = stol(s), diff = LONG_MAX, num = LONG_MAX;
        if (n == 1) {
            return to_string(v - 1);
        }
        lli pow = 1;
        for (int i = 0; i < n - 1; i++) {
            pow = pow * 1LL * 10;
        }
        lli c1 = pow - 1;
        p.push_back(c1);
        pow = pow * 1LL * 10;
        lli c2 = pow + 1;
        p.push_back(c2);
        
        string mid = s.substr(0, (n + 1) / 2);
        lli no = stol(mid);
        for (int d = -1; d <= 1; d++) {
            lli y = no + d;
            string l = to_string(y);
            string r = l;
            reverse(begin(r), end(r));
            if (n % 2 == 1) {
                l.pop_back();
            }
            l += r;
            lli x = stol(l);
            p.push_back(x);
        }
        for (auto x : p) {
            if(x==v){
                continue;
            }
            if (abs(v - x) < diff) {
                diff = abs(v - x);
                num = x;
            }
            else if (abs(v - x) == diff) {
                num = min(num, x);
            }
        }
        return to_string(num);
    }
};