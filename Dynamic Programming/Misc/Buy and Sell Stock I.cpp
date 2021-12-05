// one transaction allowed
int maxProfit(vector<int>& prices) {
    int leastProfit =INT_MAX;
    int profit=0;
    for(int i=0;i<prices.size();i++)
    {
        if(prices[i]<leastProfit)
            leastProfit=prices[i];
        
        int profitIfSoldToday = prices[i] - leastProfit;
        profit = max(profit, profitIfSoldToday);
    }
    return profit;
}