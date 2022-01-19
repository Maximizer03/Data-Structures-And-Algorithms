class Solution {
private :
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
          if (parent[v] == v) {
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
     int makeConnected(int n, vector<vector<int>>& connections) {
          int m = connections.size();
          if (m < n - 1) {
               return -1;
          }
          init(n);
          for (auto x : connections) {
               union_sets(x[0], x[1]);
          }
          int ans = 0;
          set<int>s;
          for (int i = 0; i < n; i++) {
               s.insert(find_set(i));
          }
          return s.size() - 1;
     }
};