class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        vector<int>arr;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            arr.push_back(nums2[j]);
            j++;
        }
        if((n+m)%2){
            double ans= arr[(n+m)/2];
            return ans;
        }
        else{
            int right= (n+m)/2;
            int left= right-1;
            double ans= (arr[left]+arr[left+1])/2.0;
            return ans;
        }
    }
};