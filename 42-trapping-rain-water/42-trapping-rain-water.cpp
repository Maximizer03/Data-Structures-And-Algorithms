class Solution {
public:
    int trap(vector<int>& h) {
        // come here later and learn O(1) space soln
        int n=h.size();
        vector<int>p(n,INT_MIN),s(n,INT_MIN);
        for(int i=0;i<n;i++){
            p[i]=h[i];
            if(i){
                p[i]=max(p[i],p[i-1]);
            }
        }
        for(int i=n-1;i>=0;i--){
            s[i]=h[i];
            if(i+1<n){
                s[i]=max(s[i],s[i+1]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= min(p[i],s[i])-h[i];
        }
        return ans;
    }
};