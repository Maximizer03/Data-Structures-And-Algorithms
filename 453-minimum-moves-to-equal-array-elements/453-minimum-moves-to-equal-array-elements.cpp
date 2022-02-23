class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+= nums[i]-nums[0];
        }
        return ans;
    }
};