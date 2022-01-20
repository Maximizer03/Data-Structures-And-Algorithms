class Solution {
public:
     int maximalNetworkRank(int n, vector<vector<int>>& roads) {
          int m = roads.size();
          vector<int>degree(n, 0);
          for (auto e : roads) {
               degree[e[0]]++;
               degree[e[1]]++;
          }
          int fmax = 0, smax = 0;
          for (int i = 0; i < n; i++) {
               if (degree[i] > fmax) {
                    smax = fmax;
                    fmax = degree[i];
               }
               else if (degree[i] > smax && degree[i] != fmax) {
                    smax = degree[i];
               }
          }
          int cntf = 0, cnts = 0;
          for (int i = 0; i < n; i++) {
               if (degree[i] == fmax) {
                    cntf++;
               }
               else if (degree[i] == smax) {
                    cnts++;
               }
          }
          if (cntf == 1) {
               int cnt = 0;
               // number of edges with [fmax,smax]
               for (auto e : roads) {
                    int u = e[0], v = e[1];
                    if (degree[u] == fmax && degree[v] == smax) {
                         cnt++;
                    }
                    else if (degree[u] == smax && degree[v] == fmax) {
                         cnt++;
                    }
               }
               int v = 0;
               if (cnt == cnts) {
                    v = -1;
               }
               return fmax + smax + v;
          }
          else {
               int cnt = 0;
               for (auto e : roads) {
                    int u = e[0], v = e[1];
                    if (degree[u] == fmax && degree[v] == fmax) {
                         cnt++;
                    }
               }
               int v = 0;
               if (cnt == (cntf * (cntf - 1)) / 2) {
                    v = -1;
               }
               return 2 * fmax + v;
          }
     }
};