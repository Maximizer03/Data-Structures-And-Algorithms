class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        int ans=0,sum=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]+sum>=0){
                sum+=s[i];
                ans+=sum;
            }
        }
        return ans;
    }
};