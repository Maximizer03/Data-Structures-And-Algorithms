class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<long long>cnt(33,0);
        for(int x:nums){
            x=abs(x);
            for(int j=0;j<=32;j++){
                long long bit=(1LL<<j)&x;
                if(bit){
                    cnt[j]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<33;i++){
            if(cnt[i]%3==1){
                ans= ans | (1LL<<i);
            }
        }
        int v=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans){
                v++;
            }
        }
        if(v==1){
            return ans;
        }
        else{
            return -1*ans;
        }
    }
};