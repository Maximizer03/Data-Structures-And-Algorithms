class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int mx=-1e9;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        mx=max(mx,sum);
        for(int i=k;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-k];
            mx=max(mx,sum);
        }
        double ans= mx/(k*1.0);
        return ans;
        
    }
};