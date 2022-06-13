class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=-1;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long rem= sum%(long long)(k);
            int r= rem;
            if(m.find(r)==m.end()){
                m[r]=i;
            }
            else{
                int len= i-m[r];
                if(len>=2){
                    return true;
                }
            }
        }
        return false;
    }
};