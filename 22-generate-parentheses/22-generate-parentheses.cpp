class Solution {
public:
     void backtrack(vector<string>&a, string s, int open, int close, int n) {
          if (open == n && close == n) {
               a.push_back(s);
               return;
          }
          if (open < n) {
               backtrack(a, s + '(', open + 1, close, n);
          }
          if (close < open) {
               backtrack(a, s + ')', open, close + 1, n);
          }
     }
     vector<string> generateParenthesis(int n) {
          vector<string>a;
          int open = 0, close = 0;
          backtrack(a, "", open, close, n);
          return a;
     }
};