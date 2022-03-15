class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();
        bitset<70*70+1>bit;
        int mx=0;
        for(int i=0;i<n;i++){
            bitset<70*70+1>cur_bit;
            int cur_mx=0;
            for(auto &x: unordered_set(begin(mat[i]),end(mat[i]))){
                for(int j=0;j<=mx;j++){
                    if(bit[j]==true || j==mx){
                        cur_bit[x+j]=true;
                        cur_mx=max(cur_mx,x+j);
                    }
                }
            }
            bit=cur_bit;
            mx=cur_mx;
        }
        int ans=1e9;
        for(int i=0;i<70*70+1;i++){
            if(bit[i]==true){
                ans=min(ans,abs(target-i));
            }
        }
        return ans;
    }
};