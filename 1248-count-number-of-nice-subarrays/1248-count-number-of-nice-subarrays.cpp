class Solution {
public:
    // calc(array,k)=> number of subarrays with sum atmost k
    int calc(vector<int>&a, int k){
        if(k<0){
            return 0;
        }
        int n=a.size();
        int i=0,ans=0;
        for(int j=0;j<n;j++){
            k-=a[j];
            while(k<0){
                k+=a[i];
                i++;
            }
            // number of subarrays ending at j and starting from [i....j]
            ans+=(j-i+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        return calc(nums,k)-calc(nums,k-1);
    }
};