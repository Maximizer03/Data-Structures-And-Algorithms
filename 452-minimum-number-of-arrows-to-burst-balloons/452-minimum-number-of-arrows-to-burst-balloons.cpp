class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int n = p.size();
        sort(begin(p), end(p), [&](const vector<int>&a, const vector<int>&b) {
            if (a[1] == b[1]) {
                return a[0] <= b[0];
            }
            else {
                return a[1] < b[1];
            }
        });
        // [1,6] [2,8] [7,12] [10,16]
        int cnt = n;
        int  right = p[0][1];
        for(int i=1;i<n;i++){
            if(right>=p[i][0]){
                cnt--;
            }
            else{
                right=p[i][1];
            }
        }
        return cnt;
    }
};