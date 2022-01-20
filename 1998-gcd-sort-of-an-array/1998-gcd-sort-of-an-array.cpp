class Solution {
     // DSU code
private:
     vector<int>parent, rank;
public:
     void init(int n) {
          parent.resize(n + 1);
          rank.resize(n + 1);
          for (int i = 0; i <= n; i++) {
               parent[i] = i;
               rank[i] = 0;
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
               parent[b] = a;
               if (rank[a] < rank[b]) {
                    swap(a, b);
               }
               if (rank[a] == rank[b]) {
                    rank[a]++;
               }
          }
     }
     // DSU code
     bool gcdSort(vector<int>& nums) {
          int n = nums.size();
          int mx = *max_element(begin(nums), end(nums));
          init(mx + 1);
          for (int i = 0; i < n; i++) {
               int x = nums[i];
               for (int j = 2; j * j <= x; j++) {
                    if (x % j == 0) {
                         int f1 = j, f2 = x / j;
                         union_sets(x, f1);
                         union_sets(x, f2);
                    }
               }
          }
          vector<int>a = nums;
          sort(begin(a), end(a));
          for (int i = 0; i < n; i++) {
               if (find_set(a[i]) != find_set(nums[i])) {
                    return false;
               }
          }
          return true;
     }
};