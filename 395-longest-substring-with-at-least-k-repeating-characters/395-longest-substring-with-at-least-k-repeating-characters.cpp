class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(k>n){
            return 0;
        }
        vector<int>cnt(26,0);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        int l=0;
        while(l<n){
            if(cnt[s[l]-'a']>=k){
                l++;
            }
            else{
                break;
            }
        }
        if(l>n-1){
           return l;
        }
        string t="";
        for(int i=0;i<l;i++){
            t+=s[i];
        }
        int a= longestSubstring(t,k);
        int b=0;
        while(l<n && cnt[s[l]-'a']<k){
            l++;
        }
        if(l==n){
            b=0;
        }
        else{
            string r="";
            for(int i=l;i<n;i++){
                r+=s[i];
            }
            b=longestSubstring(r,k);
        }
        return max(a,b);
    }
};