int dp[100][10001];
int solve(vector<int>& coins, int n, int amount){
    if(n==0)
        return INT_MAX-1;
    else if(amount==0)
        return 0;
    if(dp[n-1][amount]!=-1)
        return dp[n-1][amount];
    else if(coins[n-1]<=amount)
        return dp[n-1][amount] = min(solve(coins, n, amount-coins[n-1])+1, solve(coins, n-1, amount));
    else
        return dp[n-1][amount] = solve(coins, n-1, amount);
}
int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof dp);
    int ans = solve(coins, coins.size(), amount);
    if(ans>=INT_MAX-1)
        return -1;
    else return ans;
}