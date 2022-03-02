class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,-1e9);
        vector<int>dp2(n,1e9);
        // dp1[i]=> max product subarray ending at i
        // dp2[i]=> min prduct subarray ending at i
        dp1[0]=dp2[0]=nums[0];
        int mx=nums[0];
        for(int i=1;i<n;i++){
            dp1[i]=max({nums[i],nums[i]*dp1[i-1],nums[i]*dp2[i-1]});
            dp2[i]=min({nums[i],nums[i]*dp2[i-1],nums[i]*dp1[i-1]});
            mx=max({mx,dp1[i],dp2[i]});
        }
        return mx;
    }
};