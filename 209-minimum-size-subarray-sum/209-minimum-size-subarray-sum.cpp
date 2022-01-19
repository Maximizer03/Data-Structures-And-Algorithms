class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        int i=0,mn=n+1;
        for(int j=0;j<n;j++){
            s-=nums[j];
            while(s<=0){
                mn=min(mn,j-i+1);
                s+=nums[i];
                i++;
            }
        }
        return mn%(n+1);
    }
};