class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>L(n,-1),R(n,n);
        stack<pair<int,int>>st;
        // (value,index)
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=h[i]){
                st.pop();
            }
            if(!st.empty()){
                L[i]=st.top().second;
            }
            st.push({h[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=h[i]){
                st.pop();
            }
            if(!st.empty()){
                R[i]=st.top().second;
            }
            st.push({h[i],i});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(R[i]-L[i]-1)*h[i]);
        }
        return ans;
    }
};