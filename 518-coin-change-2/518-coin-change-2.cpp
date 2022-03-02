class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(sum+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            vector<int>cur(sum+1,0);
            cur[0]=1;
            for(int j=1;j<=sum;j++){
                cur[j]=prev[j];
                if(j-coins[i-1]>=0){
                    cur[j]+=cur[j-coins[i-1]];
                }
            }
            prev=cur;
        }
        return prev.back();
    }
};