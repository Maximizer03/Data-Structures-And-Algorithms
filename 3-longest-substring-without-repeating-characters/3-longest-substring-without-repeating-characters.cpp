class Solution {
public:
      int lengthOfLongestSubstring(string s) {
            int n=s.size();
          vector<int>m(256,-1);
          int l=0,r=0;
          int mx=0;
          while(r<n){
              if(m[s[r]]!=-1){
                  l=max(l,m[s[r]]+1);
              }
              m[s[r]]=r;
              mx=max(mx,r-l+1);
              r++;
          }
          return mx;
      }
};