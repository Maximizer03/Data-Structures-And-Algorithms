class Solution {
public:
    void dfs(int v, int p, vector<int>&vis,vector<vector<int>>&g){
        vis[v]=1;
        for(auto u:g[v]){
            if(u!=p && vis[u]==0){
                dfs(u,v,vis,g);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int>order,indegree(n,0),vis(n,0);
        vector<vector<int>>g(n);
        for(auto x:edges){
            // u->v
            int u=x[0],v=x[1];
            g[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            order.push_back(v);
            for(auto u:g[v]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
        }
        vector<int>ans;
        for(auto v:order){
            if(!vis[v]){
                ans.push_back(v);
                dfs(v,-1,vis,g);
            }
        }
        return ans;
    }
};