class Solution {
public:
    void calc(int i, int n, vector<int>&arr, vector<int>comb,                                   vector<vector<int>>&ans, int tar, int sum){
        if(sum>tar){
            return;
        }
        if(i==n){
            if(sum==tar){
                ans.push_back(comb);
            }
            return;
        }
        
        sum+=arr[i];
        comb.push_back(arr[i]);
        calc(i,n,arr,comb,ans,tar,sum);
        sum-=arr[i];
        comb.pop_back();
        
        calc(i+1,n,arr,comb,ans,tar,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        int n=arr.size();
        vector<vector<int>>ans;
        vector<int>comb;
        sort(arr.begin(),arr.end());
        calc(0,n,arr,comb,ans,tar,0);
        return ans;
    }
};