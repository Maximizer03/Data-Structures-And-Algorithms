class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int maxProfit=0,cheapest=prices[0];
        for(int i=1;i<prices.size();i++){
            maxProfit=max(maxProfit,prices[i]-cheapest);
            cheapest=min(cheapest,prices[i]);
        }
        return maxProfit;
    }
};