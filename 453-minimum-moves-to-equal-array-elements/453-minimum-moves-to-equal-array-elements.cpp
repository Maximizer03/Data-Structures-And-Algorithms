class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long mn=1e12;
        long long n= nums.size();
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mn=min(mn,(long long)nums[i]);
        }
        return sum-n*mn;
    }
};