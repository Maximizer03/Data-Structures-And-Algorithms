class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>L(n,-1),R(n,n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                L[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                R[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int left= L[i]+1;
            int right= R[i]-1;
            if(k>=left && k<=right){
                ans=max(ans,nums[i]*(right-left+1));
            }
        }
        return ans;
    }
};