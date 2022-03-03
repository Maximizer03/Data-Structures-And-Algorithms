class Solution {
public:
    int ans;
    bool isPalindrome(string &s){
        bool ans=true;
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;r--;
            }
            else{
                return false;
            }
        }
        return ans;
    }
    void calc(int i, string &s, string &s1, string &s2){
        if(i==s.size()){
            if(isPalindrome(s1) && isPalindrome(s2)){
                int t1=s1.size();
                int t2= s2.size();
                ans=max(ans,t1*t2);
            }
            return;
        }
        s1.push_back(s[i]);
        calc(i+1,s,s1,s2);
        s1.pop_back();
        
        s2.push_back(s[i]);
        calc(i+1,s,s1,s2);
        s2.pop_back();
        
        calc(i+1,s,s1,s2);
    }
    int maxProduct(string s) {
        string s1="",s2="";
        ans=0;
        calc(0,s,s1,s2);
        return ans;
    }
};