class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int n=nums.size();
        m[0]++;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};