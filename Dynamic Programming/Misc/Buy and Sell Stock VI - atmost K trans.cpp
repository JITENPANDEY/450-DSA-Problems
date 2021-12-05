// O(N^3) 
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(k==0 || n==0) return 0;
    int dp[k+1][n];
    
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else{
                int max_profit = 0;
                for(int it=0;it<j;it++){
                  max_profit = max(max_profit, prices[j]-prices[it] + dp[i-1][it]); 
                }
                dp[i][j] =  max(dp[i][j-1], max_profit);
            }
        }
    }
    return dp[k][n-1];
}
    // Your input
    // 2
    // [3,3,5,0,0,3,1,4]
    // stdout
    // 0 0 0 0 0 0 0 0 
    // 0 0 2 2 2 3 3 4 
    // 0 0 2 2 2 5 5 6 

// O(N^2)
int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k==0 || n==0) return 0;
        int dp[k+1][n];
        
        for(int i=0;i<=k;i++){
            int max_profit = INT_MIN;
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else{
                    max_profit = max(max_profit, dp[i-1][j-1] - prices[j-1]);
                    dp[i][j] =  max(dp[i][j-1], max_profit + prices[j]);
                }
            }
        }
        return dp[k][n-1];
    }
    // Your input
    // 2
    // [3,3,5,0,0,3,1,4]
    // stdout
    // 0 0 0 0 0 0 0 0 
    // 0 0 2 2 2 3 3 4 
    // 0 0 2 2 2 5 5 6 