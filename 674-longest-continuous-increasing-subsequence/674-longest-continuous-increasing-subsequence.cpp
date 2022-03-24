class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                dp[i]=1+dp[i-1];
            }
        }
        return *max_element(begin(dp),end(dp));
    }
};