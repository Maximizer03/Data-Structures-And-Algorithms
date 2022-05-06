class Solution {
public:
    int dp[55][1<<10], sum[1<<10], n, m;
    vector<int> v;
    bool calc(int i, int mask){
        if(i == v.size()) {
            return mask == (1 << m) - 1;
        }
        if(dp[i][mask]!=-1){
            return dp[i][mask];
        }
        int ans=0;
        for(int mask2 = 0; mask2 < (1<<m); mask2++) {
            if(mask & mask2 || sum[mask2] > v[i]) {
                continue;
            }
            ans |= calc(i+1, mask | mask2);
        }
        return dp[i][mask]=ans;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        n = nums.size(), m = quantity.size();
        memset(dp, -1, sizeof dp);
        memset(sum, 0, sizeof sum); 
        v.clear();
        
        vector<int> cnt(1005);
        for(int x : nums) {
            ++cnt[x];
        }
        for(int i = 0; i <= 1000; i++) if(cnt[i]) v.push_back(cnt[i]);
        
        for(int i = 0; i <(1<<m); i++) {
            for(int j = 0; j < m; j++){
                int bit= (1<<j)&i;
                if(bit>0){
                    sum[i]+=quantity[j];
                }
            }
        }
        return calc(0, 0);
    }
};