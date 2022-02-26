class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>productArray(nums.size());
        productArray[0]=1;
        for(int i=1;i<nums.size();i++){
            productArray[i]=productArray[i-1]*nums[i-1];
        }
        int rightProduct=1;
        for(int i=nums.size()-1;i>=0;i--){
            productArray[i]*=rightProduct;
            rightProduct*= nums[i];
        }
        return productArray;
    }
};