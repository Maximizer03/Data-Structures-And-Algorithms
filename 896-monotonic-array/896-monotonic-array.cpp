class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true,dec=true;
        for(int i=1;i<nums.size();i++){
            inc &= (nums[i]>=nums[i-1]);
            dec &= (nums[i]<=nums[i-1]);
        }
        return (inc || dec);
    }
};