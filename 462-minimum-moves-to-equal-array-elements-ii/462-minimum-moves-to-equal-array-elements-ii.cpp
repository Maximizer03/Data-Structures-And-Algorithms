class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int x=(n)/2;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+= abs(nums[i]-nums[x]);
        }
        return sum;
    }
};