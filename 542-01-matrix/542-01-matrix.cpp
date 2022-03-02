class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx= x+dx[k];
                int ny= y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                    ans[nx][ny]=ans[x][y]+1;
                }
            }
            
        }
        return ans;
    }
};