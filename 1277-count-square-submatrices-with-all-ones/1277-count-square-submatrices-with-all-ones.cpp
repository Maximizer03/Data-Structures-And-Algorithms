class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(i-1>=0 && j-1>=0){
                        if(mat[i-1][j-1]>0 && mat[i-1][j]>0 && mat[i][j-1]>0){
                            mat[i][j]=1+min({mat[i-1][j-1],mat[i][j-1],mat[i-1][j]});
                        }
                    }
                }
                cnt+=mat[i][j];
            }
        }
        return cnt;
    }
};