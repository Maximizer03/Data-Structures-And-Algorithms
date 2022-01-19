class Solution {
public:
    int calc(vector<int>&a, int k){
        if(k<0){
            return 0;
        }
        int n=a.size(),ans=0,i=0;
        for(int j=0;j<n;j++){
            k-=a[j];
            while(k<0){
                k+=a[i];
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n=nums.size();
        return calc(nums,k)-calc(nums,k-1);
    }
};