class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int gcd1= __gcd(nums[i],k);
            int gcd2= k/gcd1;
            if(gcd2==1){
                ans+=i;
            }
            else{
                for(auto &x:cnt){
                    if(x.first% gcd2==0){
                        ans+=x.second;
                    }
                }
            }
            cnt[gcd1]++;
        }
        return ans;
    }
};