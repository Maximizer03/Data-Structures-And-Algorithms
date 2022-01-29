class Solution {
private:
     vector<int>parent, rank;
public:
     void init(int n) {
          parent.resize(n + 1);
          rank.resize(n + 1);
          for (int v = 0; v <= n; v++) {
               parent[v] = v;
               rank[v] = 0;
          }
     }
     int find_set(int v) {
          if (v == parent[v]) {
               return v;
          }
          return parent[v] = find_set(parent[v]);
     }
     void union_sets(int a, int b) {
          a = find_set(a);
          b = find_set(b);
          if (a != b) {
               if (rank[a] < rank[b]) {
                    swap(a, b);
               }
               parent[b] = a;
               if (rank[a] == rank[b]) {
                    rank[a]++;
               }
          }
     }
     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
          int m=edges.size();
          init(m+1);
          for(int i=0;i<m;i++){
             int u=edges[i][0],v=edges[i][1];
             if(find_set(u)==find_set(v)){
                 return {u,v};
             }
             union_sets(u,v);
         }
         return {0,0};
     }
};