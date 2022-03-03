class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        // mat[i][j]=> if person i knows language j
        for(int i=0;i<languages.size();i++){
            for(auto &u:languages[i]){
                mat[i][u-1]=1;
            }
        }
        set<int>not_perfect;
        for(vector<int> edge:friendships){
            int u= edge[0]-1;
            int v= edge[1]-1;
            bool good=false;
            for(int j=0;j<n;j++){
                if(mat[u][j]==1 && mat[v][j]==1){
                    good=true;
                }
            }
            if(!good){
                not_perfect.insert(u);
                not_perfect.insert(v);
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(auto &x:not_perfect){
                if(mat[x][i]==0){
                    cnt++;
                }
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};