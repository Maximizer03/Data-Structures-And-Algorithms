class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f0=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            f0+= i*nums[i];
            sum+=nums[i];
        }
        int mx=-1e9;
        vector<int>fdp(n);
        int prev= f0;
        mx=prev;
        for(int i=1;i<n;i++){
            int cur= sum+ prev - n*nums[n-i];
            mx=max(mx,cur);
            prev=cur;
        }
        return mx;
    }
};