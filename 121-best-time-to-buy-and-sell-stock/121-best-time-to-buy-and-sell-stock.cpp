class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=1e6;
        int mx=0;
        for(auto &x:prices){
            mx=max(mx,x-mn);
            mn=min(mn,x);
        }
        return mx;
    }
};