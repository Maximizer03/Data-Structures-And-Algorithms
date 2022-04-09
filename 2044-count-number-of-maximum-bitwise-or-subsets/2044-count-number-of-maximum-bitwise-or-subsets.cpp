class Solution {
public:
    int countMaxOrSubsets(vector<int>& v) {
        int n=v.size();
        int mx=0;
        for(int m=0;m<(1<<n);m++){
            int ans=0;
            for(int j=0;j<n;j++){
                int bit= (1<<j)&m;
                if(bit>0){
                    ans = ans | (v[j]);
                }
            }
            mx=max(mx,ans);
        }
        int cnt=0;
        for(int m=0;m<(1<<n);m++){
            int ans=0;
            for(int j=0;j<n;j++){
                int bit= (1<<j)&m;
                if(bit>0){
                    ans = ans | (v[j]);
                }
            }
            if(ans==mx){
                cnt++;
            }
        }
        return cnt;
    }
};