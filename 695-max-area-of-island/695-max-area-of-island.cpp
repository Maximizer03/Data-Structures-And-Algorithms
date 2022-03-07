class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid, int &cnt){
        int n=grid.size(),m=grid[0].size();
        if(i<0 || i>=n ||j<0 ||j>=m || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        cnt++;
        dfs(i+1,j,grid,cnt);
        dfs(i-1,j,grid,cnt);
        dfs(i,j+1,grid,cnt);
        dfs(i,j-1,grid,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    dfs(i,j,grid,cnt);
                    max_area=max(max_area,cnt);
                }
            }
        }
        return max_area;
    }
};