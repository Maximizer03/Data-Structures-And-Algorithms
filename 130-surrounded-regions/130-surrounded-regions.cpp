class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&board){
        int n=board.size();
        int m=board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='X' || board[i][j]=='#'){
            return;
        }
        board[i][j]='#';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    if(i==0 || j==0 || i==n-1 || j==m-1){
                        dfs(i,j,board);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};