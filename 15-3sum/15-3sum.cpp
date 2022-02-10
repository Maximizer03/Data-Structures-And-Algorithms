class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        if(n==0){
            return ans;
        }
        for(int i=0;i<n;i++){
            int left=i+1,right=n-1;
            int tar= -1*nums[i];
            int x=nums[i];
            if(i>0){
                if(nums[i]==nums[i-1]){
                    continue;
                }
            }
            while(left<right){
                int sum= nums[left]+nums[right];
                if(sum<tar){
                    left++;
                }
                else if(sum>tar){
                    right--;
                }
                else{
                    int f= nums[i];
                    int s= nums[left];
                    int t= nums[right];
                    vector<int>v={f,s,t};
                    ans.push_back(v);
                    while(left<right && nums[left]==s){
                        left++;
                    }
                    while(left<right && nums[right]==t){
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};