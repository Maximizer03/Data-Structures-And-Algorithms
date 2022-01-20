class Solution {
private:
    vector<vector<int>>g;
    vector<int>tm;
public:
    int ans;
    void dfs(int v, int p,  int t){
        ans=max(ans,t);
        for(auto u:g[v]){
            if(u!=p){
                dfs(u,v,t+tm[v]);
            }
        }
    }
    int numOfMinutes(int n, int root, vector<int>& manager, vector<int>& informTime) {
        g=vector<vector<int>>(n);
        tm=informTime;
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                int u=i;
                int v= manager[i];
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        ans=0;
        dfs(root,-1,0);
        return ans;
    }
};