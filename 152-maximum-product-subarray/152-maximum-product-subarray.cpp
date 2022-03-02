class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pmaxi=nums[0];
        int pmini=nums[0];
        int mx=nums[0];
        for(int i=1;i<n;i++){
            int cmaxi=max({nums[i],nums[i]*pmaxi,nums[i]*pmini});
            int cmini=min({nums[i],nums[i]*pmaxi,nums[i]*pmini});
            mx=max({mx,cmaxi,cmini});
            pmaxi=cmaxi;
            pmini=cmini;
        }
        return mx;
    }
};