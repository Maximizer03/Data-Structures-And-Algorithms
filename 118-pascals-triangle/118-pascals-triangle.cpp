class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n);
        ans[0]={1};
        vector<int>p=ans[0];
        for(int i=2;i<=n;i++){
            vector<int>v(i,1);
            for(int j=1;j<i-1;j++){
                v[j]=p[j]+p[j-1];
            }
            ans[i-1]=v;
            p=v;
        }
        return ans;
    }
};