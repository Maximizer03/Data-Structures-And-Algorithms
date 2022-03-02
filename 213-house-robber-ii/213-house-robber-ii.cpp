class Solution {
public:
    int calc(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2));
        int not_taken=0;
        int taken=nums[0];
        // O(n) time complexity and O(1) space complexity
        for(int i=1;i<n;i++){
            int curnot_taken= max(not_taken,taken);
            int cur_taken= not_taken+nums[i];
            
            not_taken=curnot_taken;
            taken=cur_taken;
        }
        return max(not_taken,taken);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>v1,v2;
        for(int i=0;i<n-1;i++){
            v1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            v2.push_back(nums[i]);
        }
        return max(calc(v1),calc(v2));
    }
};