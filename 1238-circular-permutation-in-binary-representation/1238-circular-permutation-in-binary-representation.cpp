class Solution {
public:
    int calc(string &s){
        int n=s.size();
        int p=1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=p;
            }
            p*=2;
        }
        return ans;
    }
    void solve(int n, vector<string>&ans){
        if(n==1){
            ans.push_back("0");
            ans.push_back("1");
            return;
        }
        solve(n-1,ans);
        vector<string>temp;
        for(int i=0;i<ans.size();i++){
            string k= '0'+ans[i];
            temp.push_back(k);
        }
        for(int i=ans.size()-1;i>=0;i--){
            string k='1'+ans[i];
            temp.push_back(k);
        }
        ans=temp;
    }
    vector<int> circularPermutation(int n, int start) {
        vector<string>ans;
        solve(n,ans);
        vector<int>k;
        for(int i=0;i<ans.size();i++){
            k.push_back(calc(ans[i]));
        }
        int ind=-1;
        for(int i=0;i<k.size();i++){
            if(k[i]==start){
                ind=i;
                break;
            }
        }
        vector<int>f;
        for(int i=ind;i<k.size();i++){
            f.push_back(k[i]);
        }
        for(int i=0;i<ind;i++){
            f.push_back(k[i]);
        }
        return f;
    }
};