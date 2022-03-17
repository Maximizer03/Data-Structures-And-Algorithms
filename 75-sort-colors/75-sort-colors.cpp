class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flag algo
        // all 0's from [0...low-1]
        // all 2's from [high+1....n]
        // all 1's from [low.....mid-1]
        // Algo
        // if mid==0 swap(low,mid) mid++ low++
        // if mid==1 mid++
        // if  mid==2 swap(mid,high)  high--
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            int x=nums[mid];
            if(x==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(x==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};