class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int l=0,r=n-1,cnt=0;
        while(l<r){
            int sum= nums[l]+nums[r];
            if(sum>k){
                r--;
            }
            else if(sum<k){
                l++;
            }
            else{
                cnt++;
                l++;r--;
            }
        }
        return cnt;
    }
};