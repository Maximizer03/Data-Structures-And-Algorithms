class Solution {
public:
     int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
          int n = words.size();
          vector<int>f(26, 0);
          for (auto ch : letters) {
               int v = ch - 'a';
               f[v]++;
          }
          int mx = 0;
          for (int i = 0; i < (1 << n); i++) {
               vector<int>rf(26, 0);
               for (int j = 0; j < n; j++) {
                    int bit = (1 << j)&i;
                    if (bit > 0) {
                         for (auto ch : words[j]) {
                              int v = ch - 'a';
                              rf[v]++;
                         }
                    }
               }
               bool flg = 1;
               for (int j = 0; j < 26; j++) {
                    if (f[j] < rf[j]) {
                         flg = 0;
                         break;
                    }
               }
               if (flg) {
                    int ans = 0;
                    for (int j = 0; j < 26; j++) {
                         ans += rf[j] * score[j];
                    }
                    mx = max(mx, ans);
               }
          }
          return mx;
     }
};