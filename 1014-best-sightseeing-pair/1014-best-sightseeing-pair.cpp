class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size();
        int mx= v[0];
        int ans=-1e9;
        for(int i=1;i<n;i++){
            ans=max(ans,mx+v[i]-i);
            mx=max(mx,v[i]+i);
        }
        return ans;
    }
};