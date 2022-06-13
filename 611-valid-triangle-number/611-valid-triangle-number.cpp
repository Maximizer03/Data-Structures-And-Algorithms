class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n=a.size();
        sort(begin(a),end(a));
        int ans=0;
       for(int i=n-1;i>1;i--){
           int l=0,r=i-1;
           while(l<r){
               if(a[l]+a[r]>a[i]){
                   ans+=r-l;
                   r--;
               }
               else{
                   l++;
               }
           }
       }
        return ans;
    }
};