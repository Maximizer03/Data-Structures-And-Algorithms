class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>a(26,0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']=i;
        }
        int st=-1;
        vector<int>ans;
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,a[s[i]-'a']);
            if(mx==i){
                ans.push_back(i-st);
                st=i;
            }
        }
        return ans;
    }
};