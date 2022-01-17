class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n+5,0);
        for(auto x:nums){
            if(x<=n && x>0){
                a[x]++;
            }
        }
        for(int i=1;i<=n+5;i++){
            if(a[i]==0){
                return i;
            }
        }
        return -1;
    }
};