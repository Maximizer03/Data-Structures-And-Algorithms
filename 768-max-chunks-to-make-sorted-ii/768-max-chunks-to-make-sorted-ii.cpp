class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>v=arr;
        sort(arr.begin(),arr.end());
        long long s1=0,s2=0;
        int ans=0;
        for(int i=0;i<n;i++){
            s1+=v[i];
            s2+=arr[i];
            if(s1==s2){
                ans++;
            }
        }
        return ans;
    }
};